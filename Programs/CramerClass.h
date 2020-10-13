#ifndef CRAMMERCLASS_H
#define CRAMMERCLASS_H
#include "OBE.h"

class CramerClass{
    public:
        void Cramer();
        float GetDeterminant(float a[][N], int n, int t);
};
#endif