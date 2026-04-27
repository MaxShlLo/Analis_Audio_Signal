#ifndef FFT_H
#define FFT_H
extern int test_real[128];
extern int test_imag[128];
extern unsigned char test_mag[64];
void fft_reorder(void);
void fft_run(void);
void fft_mag(void);
#endif