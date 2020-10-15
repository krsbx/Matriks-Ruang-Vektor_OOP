#ifndef INVERSEMETHOD_H
#define INVERSEMETHOD_H
#include "Operasi.h"

class InverseMethod{
    public:
        void InverseSPLKeyboard();
        void InverseSPL(float a[][N], float b[], int n);
        float GetX(float a[][N], float b[], int n, int x);
};
#endif