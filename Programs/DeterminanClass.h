#ifndef DETERMINANCLASS_H
#define DETERMINANCLASS_H
#include "OBE.h"

class DeterminanClass{
    public:
        void ReduksiDeterminan();
        float GetDeterminant(float a[][N], int n, int t);

        void EkspansiKofaktor();
        float Ekspansi(float a[][N], int n);
        void Kofaktor(float a[][N], float CoFac[][N], int b, int k, int n);
};
#endif