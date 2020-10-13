#include<iostream>
#include "DeterminanClass.h"
using namespace std;


    #pragma region ReduksiBaris
    void DeterminanClass::ReduksiDeterminan(){
        // Deklarasi Ukuran Matrix
        int n;
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
        //Deklarasi Determinan
        //Deklarasi Matrix
        float a[n][N];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];
            }
        }
        float det = OperasiBarisElementer(a, n);
        cout << "Determinan Dari Matrix : " << det << endl;
    }

    float DeterminanClass::OperasiBarisElementer(float a[][N], int n){
        //Penentu Banyak Penukaran
        int t = 0;
        //Perulangan Pada Kolom
        for(int j = 0; j < n; j++){
            //Peroleh Index Untuk Pengecekan
            int maxId = j;
            //Peroleh Nilai Untuk Pengecekan
            float maxValue = a[maxId][j];
            //Perulangan Pada Baris
            for(int i = j+1; i < n; i++){
                //Cek Nilai Lebih Besar Dengan Nilai Mutlak
                if((a[i][j] > 0 ? a[i][j] : -1*a[i][j]) > maxValue){
                    maxId = i;
                    maxValue = a[i][j];
                }
            }

            //Return Jika 0 Pada Diagonal Utama
            if(!a[j][maxId]) return j;

            //Tukarkan Baris
            if(maxId != j) TukarBaris(a, n, j, maxId, &t);

            //Eliminasi Baris
            for(int i = j+1; i < n; i++){
                float x = a[j][j];
                float y = a[i][j];
                //Perulangan Pada Kolom
                for(int k = 0; k < n; k++){
                    //Peroleh 0
                    a[i][k] -= a[j][k] * y/x;
                }
            }
        }
        return GetDeterminant(a, n, t);
    }

    //Tukarkan Baris Pada Matrix A
    void DeterminanClass::TukarBaris(float a[][N], int n, int y1, int y2, int* t){
        //Tukarkan Nilai Pada Baris
        for(int i = 0; i < n; i++){
            float temp = a[y1][i];
            a[y1][i] = a[y2][i];
            a[y2][i] = temp;
        }
        *t += 1;
    }

    float DeterminanClass::GetDeterminant(float a[][N], int n, int t){
        float det = 1;
        //Kalikan Semua Nilai Pada Diagonal Utama
        for(int i = 0; i < n; i++){
            det *= a[i][i];
        }
        
        if(t % 2 == 1) det *= -1;

        return det;
    }
    #pragma endregion
    #pragma region Ekspansi Kofaktor
    void DeterminanClass::EkspansiKofaktor(){
        // Deklarasi Ukuran Matrix
        int n;
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
        
        //Deklarasi Matrix
        float a[n][N];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];
            }
        }
        cout << "Determinan Dari Matrix : " << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "Determinan = " << Ekspansi(a, n);
    }

    float DeterminanClass::Ekspansi(float a[][N], int n){
        int Det = 0;

        if(n == 1) return a[0][0]; //Return satu jika satu elemen saja

        //Deklarasi Kofaktor
        float CoFac[n][N];
        
        //Peroleh Kofaktor
        for(int i = 0; i < n; i++){
            //Peroleh Kofaktor
            Kofaktor(a, CoFac, 0, i, n);
            //Peroleh Determinan
            if(i%2==0) Det += a[0][i] * Ekspansi(CoFac, n-1);
            else Det += -1 * a[0][i] * Ekspansi(CoFac, n-1);
        }

        //Kembalikan Nilai Determinan
        return Det;
    }

    void DeterminanClass::Kofaktor(float a[][N], float CoFac[][N], int b, int k, int n){
        int l = 0, m = 0; //Index Dalam Pembuatan Minor
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != b && j != k){ //Bentuk Minor
                    //Mengambil Nilai Dari Matrix A ke Minor
                    CoFac[l][m++] = a[i][j];
                    //Reset Pengulangan Pada Index Minor
                    if(m == n-1){
                        m = 0;
                        l++;
                    }
                }
            }
        }
    }
    #pragma endregion