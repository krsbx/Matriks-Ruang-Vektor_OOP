#ifndef DETERMINANCLASS_H
#define DETERMINANCLASS_H
#define N 100
class DeterminanClass{
    public:
        void ReduksiDeterminan();
        float BentukSegitiga(float a[][N], int n);
        
        void EkspansiKofaktor();
        float Ekspansi(float a[][N], int n);
        void Kofaktor(float a[][N], float CoFac[][N], int b, int k, int n);
};
#endif