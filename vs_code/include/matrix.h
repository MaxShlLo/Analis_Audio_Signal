#ifndef MATRIX_H
#define MATRIX_H

#define LOAD_LOW()   PA_ODR &= ~(1 << 3)
#define LOAD_HIGH()  PA_ODR |=  (1 << 3)
#define MATR_NUM     4

extern unsigned char buf[4][8];

void max_init(void);
void max_clear(void);
void max_flush(void);
void draw_column(unsigned char col, unsigned char height);

#endif