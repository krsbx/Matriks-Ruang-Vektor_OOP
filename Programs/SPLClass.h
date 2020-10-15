#ifndef SPLCLASS_H
#define SPLCLASS_H
#include "Operasi.h"

class SPLClass{
    public:
    void SPLGaussKeyboard();
    void SPLGauss(float a[][N], int m, int n);
    void BackwardSubtitution(float a[][N], int m, int n);

    void SPLGaussJordanKeyboard();
    void SPLGaussJordan(float a[][N], int m, int n);
};
#endif
