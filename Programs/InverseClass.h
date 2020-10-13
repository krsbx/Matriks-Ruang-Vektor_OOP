#ifndef INVERSECLASS_H
#define INVERSECLASS_H

class InverseClass{
    #define N 100
    public:
        void Inverse();
        void OperasiBarisElementer(float a[][N], int n);
        void TukarBaris(float a[][N], int n, int y1, int y2);
        void BackwardPhase(float a[][N], int n);
};
#endif