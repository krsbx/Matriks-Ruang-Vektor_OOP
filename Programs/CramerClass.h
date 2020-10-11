#ifndef CRAMMERCLASS_h
#define CRAMMERCLASS_h
#define N 100
class CramerClass{
    public:
        void Cramer();
        float OperasiBarisElementer(float a[][N], float b[], int n, int s);
        float GetDeterminant(float a[][N], int n, int t);
        void TukarBaris(float a[][N], int n, int y1, int y2, int *t);
};
#endif