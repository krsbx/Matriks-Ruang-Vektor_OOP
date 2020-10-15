#include <iostream>
#include "CramerClass.h"
using namespace std;

    void CramerClass::CramerKeyboard(){
        // Deklarasi Ukuran Matrix
        int n;
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
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
        Cramer(a, b, n);
    }

    void CramerClass::Cramer(float a[][N], float b[], int n){
        //Deklarasi Determinan
        float det[n+1];

        for(int i = -1; i < n; i++){
            int swap = 0;
            float temp[n][N];
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    temp[j][k] = a[j][k];
                }
            }
            
            Operasi::OperasiBarisElementer(temp, b, 0, n, i, &swap);
            det[i+1] = Operasi::GetDeterminant(temp, n, swap);
        }
        
        cout << "Solusi Dari Persamaan Ialah : " << endl;
        for(int i = 1; i < n+1; i++){
            cout << "X[" << i << "] = " << det[i]/det[0] << endl;
        }
    }

