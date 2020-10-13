#include "InverseMethod.h"
#include "InverseClass.h"
#include<iostream>
using namespace std;

    void InverseMethod::InverseSPL(){
        // Deklarasi Ukuran Matrix
        int n;
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
        //Deklarasi Matrix
        float a[n][N];
        //Deklarasi Matrix Hasil
        float b[n];
        //Deklarasi Matrix Solusi
        float x[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];

            }
            cout << "Masukkan Hasil Dari Persamaan " << i+1 << " : ";
            cin >> b[i];
        }

        InverseClass::AddIdentitas(a, n);
        InverseClass::BentukIdentitas(a, n);
        InverseClass::BackwardPhase(a, n);

        cout << "Sehingga : " << endl;
        for(int i = 0; i < n; i++){
            cout << "X[" << i+1 << "] = ";
            x[i] = GetX(a, b, n, i);
            cout << x[i] << endl;
        }
    }

    float InverseMethod::GetX(float a[][N], float b[], int n, int x){
        float temp = 0;
        for(int j = n; j < n*2; j++){
            temp += a[x][j] * b[(j-n)];
        }   
        return temp;
    }