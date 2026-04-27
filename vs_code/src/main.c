/* main.c - STM8S103F3P6 (FFT ІДЕАЛЬНА ПЛАВНІСТЬ ТА СУПЕР ЧУТЛИВІСТЬ) */
#include "iostm8s103.h"
#include "matrix.h"
#include "fft.h"

const unsigned char bin_start[16] = {1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 18, 22, 27, 33, 40, 49};
const unsigned char bin_end[16]   = {1, 2, 3, 4, 5, 7, 9, 11, 14, 17, 21, 26, 32, 39, 48, 63};

// Додатковий масив для сирих піків перед малюванням
unsigned int raw_peaks[16]; 
unsigned char smooth_mag[16]; // Масив для плавності (SMOOTH)

/* НАЛАШТУВАННЯ ЧУТЛИВОСТІ */
#define LOW_PASS  3    // Поріг шуму (знижено до мінімуму)
#define MIC_GAIN  25    // НОВЕ: Програмний підсилювач (Множник сигналу! 4 або 5)

// ЕКВАЛАЙЗЕР: Підсилюємо баси (перші 4 стовпчики)
const unsigned char eq_curve[16] = {
    26, 20, 16, 14, 12, 12, 10, 10, 8, 8, 7, 7, 6, 6, 6, 6
};

/* -------- ГЛОБАЛЬНІ ЗМІННІ ДЛЯ АВТОПІДСИЛЕННЯ (AGC) -------- */
unsigned int dynamic_max = 30;   
unsigned char frame_counter = 0; 

void init_gpio(void) {
    PA_DDR |= (1 << 3); PA_CR1 |= (1 << 3); LOAD_HIGH();
    PC_DDR |= (1 << 5) | (1 << 6); PC_CR1 |= (1 << 5) | (1 << 6);
}

void init_adc(void) {
    PC_DDR &= ~(1 << 4);
    PC_CR1 &= ~(1 << 4);
    ADC_CR1 = 0x00;
    ADC_CR2 = 0x08; 
    ADC_CSR = 0x02;
    ADC_CR1 |= 0x01;
}

/* -------- ВЛАСНИЙ МІНІ-UART -------- */
void init_uart(void) {
    // Налаштовуємо пін PD5 (TX) як вихід
    PD_DDR |= (1 << 5);
    PD_CR1 |= (1 << 5);
    
    // Швидкість 115200 бод (для стандартної частоти 2 МГц)
    // Формула: 2 000 000 / 115200 = 17.36 (Hex: 0x0011)
    UART1_BRR2 = 0x01;
    UART1_BRR1 = 0x01;
    
    // Вмикаємо передавач (TX)
    UART1_CR2 = (1 << 3);
}

void uart_tx(unsigned char data) {
    while (!(UART1_SR & 0x80)); // Чекаємо, поки буфер звільниться
    UART1_DR = data;
}

void uart_print(const char *str) {
    while (*str) {
        uart_tx(*str++);
    }
}

void uart_print_int(unsigned int num) {
    char buf[6];
    int i = 0;
    if (num == 0) {
        uart_tx('0');
        return;
    }
    while (num > 0) {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }
    while (i > 0) {
        uart_tx(buf[--i]);
    }
}


void show_spectrum(void) {
    unsigned char col, i, height;
    unsigned int max_val, frame_peak;
    unsigned long calc_val;

    frame_peak = 0;
    
    /* ПРОХІД 1: Збираємо піки */
    for (col = 0; col < 16; col++) {
        max_val = 0;
        for (i = bin_start[col]; i <= bin_end[col]; i++) {
            if (test_mag[i] > max_val) {
                max_val = test_mag[i];
            }
        }
        
        // СПРАВЖНІЙ ШУМОДАВ: Відсікаємо електричний шум ДО множення!
        // Якщо сигнал менше LOW_PASS, ми його взагалі ігноруємо.
        if (max_val <= LOW_PASS) {
            max_val = 0;
        }
        
        calc_val = (unsigned long)max_val * eq_curve[col] * MIC_GAIN / 10;
        if (calc_val > 60000) calc_val = 60000; 
        max_val = (unsigned int)calc_val; 

        raw_peaks[col] = max_val;
        
        if (max_val > frame_peak) {
            frame_peak = max_val;
        }
    }
    
    /* РОЗУМНЕ АВТОПІДСИЛЕННЯ З ЗАХИСТОМ ВІД ТИШІ */
    if (frame_peak > dynamic_max) {
        dynamic_max = (dynamic_max * 3 + frame_peak) >> 2;
    } else {
        if (dynamic_max > 40) {
            // ЕКСПОНЕНЦІЙНЕ ПАДІННЯ: Віднімаємо 1/32 частину від самої стелі.
            // Якщо стеля 10000, вона впаде на 312 одразу!
            // Якщо стеля 100, вона впаде лише на 3.
            dynamic_max -= (dynamic_max >> 3) + 2; 
        }
    }

    /* ЖОРСТКЕ ГАСІННЯ В ТИШІ */
    if (frame_peak == 0) {
        // Якщо звуку немає взагалі, плавно "ховаємо" залишки хвилі вниз
        for (col = 0; col < 16; col++) {
            smooth_mag[col] = (unsigned char)(((unsigned int)smooth_mag[col] * 3) >> 2);
            height = (unsigned char)(((unsigned int)smooth_mag[col] * 16) / 256);
            draw_column(col, height);
        }
        max_flush();
        return; // Виходимо з функції, далі рахувати немає сенсу
    }

    /* ПРОХІД 2: Асиметрична плавність */
    for (col = 0; col < 16; col++) {
        calc_val = ((unsigned long)raw_peaks[col] * 255) / dynamic_max; 
        if (calc_val > 255) calc_val = 255;

        if (calc_val > smooth_mag[col]) {
            smooth_mag[col] = (unsigned char)calc_val; 
        } else {
            smooth_mag[col] = (unsigned char)(((unsigned int)smooth_mag[col] * 3 + calc_val) >> 2);
        }

        height = (unsigned char)(((unsigned int)smooth_mag[col] * 16) / 256);
        draw_column(col, height);
    }

    /* ВИВІД В UART ДЛЯ НАЛАШТУВАННЯ */
    uart_print("Peak: ");
    uart_print_int(frame_peak);
    uart_print(" | AGC Стеля: ");
    uart_print_int(dynamic_max);
    uart_print("\r\n"); // Перехід на новий рядок

    max_flush();
}

/* -------- MAIN -------- */
void main(void) {
    unsigned char i;
    unsigned char adc_l;
    unsigned int adc_h;
    volatile unsigned char delay;
    long dc_sum;
    int dc_offset;
    long val;

    for (i = 0; i < 16; i++) smooth_mag[i] = 0;

    init_gpio();
    init_spi();
    init_adc();
    init_uart();
    max_init();
    max_clear();

    while (1) {
        dc_sum = 0;
        
        /* 1. ЧИТАЄМО ЗВУК З МІКРОФОНА */
        for (i = 0; i < 128; i++) {
            ADC_CSR &= ~0x80;
            ADC_CR1 |= 0x01;
            while (!(ADC_CSR & 0x80));

            adc_l = ADC_DRL;
            adc_h = ADC_DRH;
            
            test_real[i] = (int)((adc_h << 8) | adc_l);
            test_imag[i] = 0; 
            
            dc_sum += test_real[i];

            for (delay = 0; delay < 15; delay++); 
        }

        /* 2. ВІДРІЗАЄМО ТИШУ ТА РОБИМО ПРОГРАМНЕ ПІДСИЛЕННЯ */
        dc_offset = (int)(dc_sum >> 7); 
        for (i = 0; i < 128; i++) {
            val = test_real[i] - dc_offset; 
            
            val = val >> 1;
            
            // Запобіжник (лімітер), щоб математика не вибухнула від гучного крику
            if (val > 150) val = 150;
            if (val < -150) val = -150;

            test_real[i] = (int)val; 
        }

        /* 3. ШВИДКЕ ПЕРЕТВОРЕННЯ ФУР'Є */
        fft_reorder();
        fft_run();
        fft_mag();

        /* 4. ВИВІД ІЗ ПЛАВНІСТЮ */
        show_spectrum();
    }
}