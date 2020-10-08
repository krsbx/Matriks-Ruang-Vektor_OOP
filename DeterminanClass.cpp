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
        float det = BentukSegitiga(a, n);
        cout << "Determinan Dari Matrix : " << det << endl;
    }
    
    float DeterminanClass::BentukSegitiga(float a[][N], int n){
        //Deklarasi Varible Determinan
        float det = 1;
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

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }

        //Peroleh Determinan
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                 //Diagonal Utama
                 if(j == i)
                    det *= a[i][j];
            }
        }
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