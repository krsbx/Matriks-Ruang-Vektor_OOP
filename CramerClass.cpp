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
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];

            }
            cout << "Masukkan Hasil Dari Persamaan " << i+1 << " : ";
            cin >> a[i][n];
        }

    //Dapatkan Determinan A
        //Membentuk Segitiga Atas
        for(int j = 0; j < n-1; j++){
            for(int i = j+1; i < n; i++){
                //Fungsi Operasi Baris Elementer
                float x = a[j][j];
                float y = a[i][j];
                for(int k = 0; k < n; k++){
                    a[i][k] -= a[j][k]*y/x;
                }
            }
        }
        
        //Peroleh Determinan
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) //Diagonal Utama
                    det[0] *= a[i][j];
            }
        }

        //Peroleh Determinan A[x]
        for(int i = 1; i < n+1; i++){
            det[i] = DeterminanHasil(a, i, n);
        }

        //Cetak Solusi Persamaan
        cout << "Solusi dari Persamaan :" << endl;
        for(int i = 1; i < n+1; i++){
            cout << "X" << i << " = " << det[i]/det[0] << "\t";
        }
    }
    
    float CramerClass::DeterminanHasil(float a[][N], int x, int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == x){
                    a[i][j] = a[i][n];
                }
            }
        }

    //Dapatkan Determinan A[x]
        //Membentuk Segitiga Atas
        for(int j = 0; j < n; j++){
            for(int i = j+1; i < n; i++){
                float x = a[j][j];
                float y = a[i][j];
                for(int k = 0; k < n; k++){
                    a[i][k] -= a[j][k]*y/x;
                }
            }
        }

        float det = 1;
        //Peroleh Determinan
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) //Diagonal Utama
                    det *= a[i][j];
            }
        }
        return det;
    }
