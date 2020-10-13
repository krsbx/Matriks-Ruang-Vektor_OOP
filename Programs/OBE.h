#ifndef OBE_H
#define OBE_H
#define N 100

class OBE{
    public:
        static float OperasiBarisElementer(float a[][N], float b[], int m, int n, int ganti, int* swap);
        static float OBE_Inverse(float a[][N], int n);
        static void TukarBaris(float a[][N], int n, int y1, int y2, int* swap);
};
#endif