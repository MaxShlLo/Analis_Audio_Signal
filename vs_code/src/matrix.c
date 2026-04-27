#include "iostm8s103.h"
#include "matrix.h"


// Перенесли з main.c (Видаляємо слово extern, бо тут ми створюємо масив фізично)
unsigned char buf[4][8];

/* -------- SPI та ВИВІД -------- */
void spi_send(unsigned char data) {
    SPI_DR = data;
    while (!(SPI_SR & 0x02));
    while (SPI_SR & 0x80);
}

void max_flush_row(unsigned char row) {
    unsigned char r = row + 1;
    LOAD_LOW();
    spi_send(r); spi_send(buf[3][row]);
    spi_send(r); spi_send(buf[2][row]);
    spi_send(r); spi_send(buf[1][row]);
    spi_send(r); spi_send(buf[0][row]);
    LOAD_HIGH();
}

void max_flush(void) {
    unsigned char row;
    for (row = 0; row < 8; row++) max_flush_row(row);
}

void max_clear(void) {
    unsigned char i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 8; j++) buf[i][j] = 0x00;
    max_flush();
}

void max_init(void) {
    unsigned char i;
    LOAD_LOW(); for(i=0; i<4; i++) { spi_send(0x0C); spi_send(0x01); } LOAD_HIGH();
    LOAD_LOW(); for(i=0; i<4; i++) { spi_send(0x0F); spi_send(0x00); } LOAD_HIGH();
    LOAD_LOW(); for(i=0; i<4; i++) { spi_send(0x09); spi_send(0x00); } LOAD_HIGH();
    LOAD_LOW(); for(i=0; i<4; i++) { spi_send(0x0B); spi_send(0x07); } LOAD_HIGH();
    LOAD_LOW(); for(i=0; i<4; i++) { spi_send(0x0A); spi_send(0x07); } LOAD_HIGH();
}

void init_spi(void) {
    SPI_CR1 = 0x00;
    SPI_CR1 |= (1 << 2) | (1 << 3) | (1 << 6);
}

void draw_column(unsigned char col, unsigned char height) {
    unsigned char p, bit, m_top, m_bot, local_col, m, phys_row;

    if (col < 8) {
        m_top = 0; m_bot = 2; local_col = col;
    } else {
        m_top = 1; m_bot = 3; local_col = col - 8;
    }

    bit = (unsigned char)(1 << local_col);

    for (p = 0; p < 8; p++) {
        buf[m_top][p] &= ~bit;
        buf[m_bot][p] &= ~bit;
    }

    for (p = 0; p < height; p++) {
        if (p < 8) {
            m = m_bot;
            phys_row = p;
        } else {
            m = m_top;
            phys_row = (p - 8); 
        }
        buf[m][phys_row] |= bit;
    }
}