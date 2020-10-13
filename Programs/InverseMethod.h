#ifndef INVERSEMETHOD_H
#define INVERSEMETHOD_H
#include "OBE.h"

class InverseMethod{
    public:
        void InverseSPL();
        float GetX(float a[][N], float b[], int n, int x);
};
#endif