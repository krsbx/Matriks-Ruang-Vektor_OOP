#include "InverseClass.h"
#include<iostream>
using namespace std;

    void InverseClass::InverseKeyboard(){
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
        Inverse(a, n);
    }

    void InverseClass::Inverse(float a[][N], int n){
        AddIdentitas(a, n);
        BentukIdentitas(a, n);
        Operasi::BackwardPhase(a, n*2, n);

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
        Operasi::OBE_Inverse(a, n);
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
