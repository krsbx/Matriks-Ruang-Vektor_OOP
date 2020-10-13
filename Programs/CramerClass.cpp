#include <iostream>
#include "CramerClass.h"
using namespace std;

    void CramerClass::Cramer(){
        // Deklarasi Ukuran Matrix
        int n;
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
        //Deklarasi Determinan
        float det[n+1];
        //Deklarasi Matrix
        float a[n][N];
        float b[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];

            }
            cout << "Masukkan Hasil Dari Persamaan " << i+1 << " : ";
            cin >> b[i];
        }
        
        for(int i = -1; i < n; i++){
            float temp[n][N];
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    temp[j][k] = a[j][k];
                }
            }
            det[i+1] = OperasiBarisElementer(temp, b, n, i);
        }
        cout << "Solusi Dari Persamaan Ialah : " << endl;
        for(int i = 1; i < n+1; i++){
            cout << "X[" << i << "] = " << det[i]/det[0] << endl;
        }
    }

    float CramerClass::OperasiBarisElementer(float a[][N], float b[], int n, int s){
        //Ganti Elemen B ke A
        if(s > -1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(j == s)
                        a[i][j] = b[i];
                }
            }
        }
        //Penentu Banyak Penukaran
        int t = 0;
        //Perulangan Pada Kolom
        for(int j = 0; j < n; j++){
            //Peroleh Index untuk Pengecekan
            int maxId = j;
            //Peroleh Nilai untuk Pengecekan
            float maxValue = a[maxId][j];
            //Perulangan Pada Baris
            for(int i = j+1; i < n; i++){
                //Cek Nilai Lebih Besar Dengan Nilai Mutlak
                if((a[i][j] > 0 ? a[i][j] : -1*a[i][j]) > maxValue){
                    maxId = i;
                    maxValue = a[i][j];
                }
            }

            //Kembalikan jika 0 Pada Diagonal Utama
            if(!a[j][maxId]) return j;

            if(maxId != j) TukarBaris(a, n, j, maxId, &t);
            
            //Eliminasi Baris //Bentuk Segitiga Atas
            for(int i = j+1; i < n; i++){
                float x = a[j][j];
                float y = a[i][j];
                //Bentuk Segitiga Atas
                for(int k = 0; k < n; k++){
                    //Peroleh 0
                    a[i][k] -= a[j][k] * y/x;
                }
            }
        }
        return GetDeterminant(a, n, t);
    }

    float CramerClass::GetDeterminant(float a[][N], int n, int t){
        //Deklarasi Variable Det
        float det = 1;

        //Peroleh Semua Perkalian Pada Diagonal Utama
        for(int i = 0; i < n; i++){
            det *= a[i][i];
        }

        if(t % 2 == 1)  det *= -1;

        //Kembalikan Nilai Diagonal Utama
        return det;
    }

    //Tukarkan Baris Pada Matrix A
    void CramerClass::TukarBaris(float a[][N], int n, int y1, int y2, int *t){
        //Penukaran Baris
        for(int i = 0; i < n; i++){
            float temp = a[y1][i];
            a[y1][i] = a[y2][i];
            a[y2][i] = temp;
        }
        *t += 1;
    }
