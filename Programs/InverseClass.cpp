#include "InverseClass.h"
#include<iostream>
using namespace std;

    void InverseClass::Inverse(){
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

        AddIdentitas(a, n);
        BentukIdentitas(a, n);
        BackwardPhase(a, n);

        cout << "Inverse Matrix A ialah : " << endl;
        for(int i = 0; i < n; i++){
            for(int j = n; j < n*2; j++){
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void InverseClass::AddIdentitas(float a[][N], int n){
        //Jadikan Augmented
        //Masukan Identitas
        for(int i = 0; i < n; i++){
            for(int j = n; j < n*2; j++){
                if(j == i+n)
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }
        OBE::OBE_Inverse(a, n);
    }

    void InverseClass::BackwardPhase(float a[][N], int n){
        //Perulangan Pada Kolom
        for(int j = n-1; j >= 0; j--){
            //Perulangan Pada Baris
            for(int i = j-1; i >= 0; i--){
                //X Untuk Matrix A
                float x1 = a[j][j];
                float x2 = a[i][j];
                //Peroleh 0 Pada Matrix A
                for(int k = n*2-1; k >= i; k--){
                    a[i][k] -= a[j][k] * x2/x1;
                }
            }
        }
    }
    
    void InverseClass::BentukIdentitas(float a[][N], int n){
        //Peroleh 1 Utama
        for(int i = 0; i < n; i++){
            float x = a[i][i];
            for(int j = 0; j < n*2; j++){
                a[i][j] /= x;
            }
        }
    }
