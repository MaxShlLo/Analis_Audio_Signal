#include "fft.h"
// Сюди переносиш sin_table, fft_bit_rev, fft_run і т.д.

/* -------- НОВА НАДІЙНА МАТЕМАТИКА FFT -------- */
int test_real[128];
int test_imag[128];
unsigned char test_mag[64];

/* Ідеальна синусоїда (амплітуда 128 = 1.0) */
const int sin_table[128] = {
    0, 6, 12, 18, 25, 31, 37, 43, 49, 55, 60, 66, 71, 76, 81, 85,
    90, 94, 98, 102, 106, 109, 112, 115, 117, 120, 122, 124, 125, 126, 127, 127,
    128, 127, 127, 126, 125, 124, 122, 120, 117, 115, 112, 109, 106, 102, 98, 94,
    90, 85, 81, 76, 71, 66, 60, 55, 49, 43, 37, 31, 25, 18, 12, 6,
    0, -6, -12, -18, -25, -31, -37, -43, -49, -55, -60, -66, -71, -76, -81, -85,
    -90, -94, -98, -102, -106, -109, -112, -115, -117, -120, -122, -124, -125, -126, -127, -127,
    -128, -127, -127, -126, -125, -124, -122, -120, -117, -115, -112, -109, -106, -102, -98, -94,
    -90, -85, -81, -76, -71, -66, -60, -55, -49, -43, -37, -31, -25, -18, -12, -6
};

/* Біт-реверс для 128 (7 біт) */
unsigned char fft_bit_rev(unsigned char x) {
    x = ((x >> 1) & 0x55) | ((x & 0x55) << 1);
    x = ((x >> 2) & 0x33) | ((x & 0x33) << 2);
    x = ((x >> 4) & 0x0F) | ((x & 0x0F) << 4);
    return x >> 1; 
}

void fft_reorder(void) {
    unsigned char i, j;
    int tmp;
    for (i = 0; i < 128; i++) {
        j = fft_bit_rev(i);
        if (i < j) {
            tmp = test_real[i];
            test_real[i] = test_real[j];
            test_real[j] = tmp;
        }
    }
}

void fft_run(void) {
    unsigned char stage, step, half, base, k;
    unsigned char step_angle, idx, forward, mirror;
    long c, s;
    int t_r, t_i;

    step = 2;
    for (stage = 0; stage < 7; stage++) {
        half = step >> 1;
        step_angle = 128 / step;

        for (base = 0; base < 128; base += step) {
            for (k = 0; k < half; k++) {
                idx = k * step_angle;
                c = sin_table[(idx + 32) % 128];
                s = -sin_table[idx]; 

                forward = base + k;
                mirror  = base + half + k;

                t_r = (int)((((long)c * test_real[mirror]) - ((long)s * test_imag[mirror])) >> 7);
                t_i = (int)((((long)s * test_real[mirror]) + ((long)c * test_imag[mirror])) >> 7);

                test_real[mirror] = test_real[forward] - t_r;
                test_imag[mirror] = test_imag[forward] - t_i;
                test_real[forward] += t_r;
                test_imag[forward] += t_i;
            }
        }
        step <<= 1;
    }
}

void fft_mag(void) {
    unsigned char i;
    unsigned long a, b, mag;

    test_mag[0] = 0;
    for (i = 1; i < 64; i++) {
        a = (test_real[i] < 0 ? -test_real[i] : test_real[i]);
        b = (test_imag[i] < 0 ? -test_imag[i] : test_imag[i]);
        
        if (a > b) mag = a + (b * 3) / 8;
        else       mag = b + (a * 3) / 8;

        mag = mag / 8; 
        if (mag > 255) mag = 255;
        test_mag[i] = (unsigned char)mag;
    }
}