#ifndef INVERSEMETHOD_H
#define INVERSEMETHOD_H
class InverseMethod{
    #define N 100
    public:
        void InverseSPL();
        float GetX(float a[][N], float b[], int n, int x);
};
#endif