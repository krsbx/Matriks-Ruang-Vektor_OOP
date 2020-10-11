#ifndef DETERMINANCLASS_H
#define DETERMINANCLASS_H
#define N 100
class DeterminanClass{
    public:
        void ReduksiDeterminan();
        float OperasiBarisElementer(float a[][N], int n);
        void TukarBaris(float a[][N], int n, int y1, int y2, int* t);
        float GetDeterminant(float a[][N], int n, int t);

        void EkspansiKofaktor();
        float Ekspansi(float a[][N], int n);
        void Kofaktor(float a[][N], float CoFac[][N], int b, int k, int n);
};
#endif