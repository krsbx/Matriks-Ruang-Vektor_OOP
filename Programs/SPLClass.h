#ifndef SPLCLASS_H
#define SPLCLASS_H
#include "OBE.h"

class SPLClass{
    public:
    void SPLGauss();
    void BackwardSubtitution(float a[][N], int m, int n);

    void SPLGaussJordan();
    float BackwardPhase(float a[][N], int m, int n);

    int OperasiBarisElementer(float a[][N], int m, int n);
    void TukarBaris(float a[][N], int n,int y1,int y2);
};
#endif
