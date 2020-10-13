#ifndef INVERSECLASS_H
#define INVERSECLASS_H
#include "OBE.h"

class InverseClass{
    public:
        void Inverse();
        void OperasiBarisElementer(float a[][N], int n);
        static void BentukIdentitas(float a[][N], int n);
        static void AddIdentitas(float a[][N], int n);
        static void BackwardPhase(float a[][N], int n);
};
#endif