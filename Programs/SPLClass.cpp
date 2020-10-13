#include<iostream>
#include "OBE.h"
#include "SPLClass.h"
using namespace std;

    #pragma region GaussElimination
    void SPLClass::SPLGauss(){
        //Deklarasi Persamaan
        int m, n;
        cout << "Masukkan Jumlah Persamaan : ";
        cin >> m;
        cout << "Masukkan Jumlah Variable : ";
        cin >> n;
        //Deklarasi Variable Persamaan
        float a[m][N];
        //Deklarasi Variable Hasil Persamaan
        for(int i = 0; i < m; i++){
            // Menerima Inputan Untuk Persamaan Ke-i
            cout << "Masukkan Persamaan " << i+1 << " : " << endl;
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Variable Ke-i
                cout << "Masukkan Variable x" << j+1 << " : ";
                cin >> a[i][j];
            }
            cout << "Masukkan Hasil Dari Persamaan : ";
            cin >> a[i][n];
        }

        int cek = OBE::OperasiBarisElementer(a, NULL, m, n, -1, NULL);

        if(cek != -1){
            cout << "Berkemungkinan Tidak Bersolusi" << endl;
            if(a[cek][n])
                cout << "Tidak Bisa Di proses" << endl;
            else
                cout << "Memiliki Solusi Banyak" << endl;
            return;
        }

        cout << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n+1; j++){
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
        BackwardSubtitution(a, m, n);
    }

    void SPLClass::BackwardSubtitution(float a[][N], int m, int n){
        float x[n];

        for(int i = m-1; i >= 0; i--){
            //Peroleh Nilai Paling Akhir
            x[i] = a[i][n];
            for(int j = i+1; j < n ;j++){
                x[i] -= a[i][j]*x[j];
            }

            //Peroleh Nilai Akhir/Solusi
            x[i] /= a[i][i];
        }
        cout << "Soulis Dari Persamaan Tersebut Ialah : " << endl;
        for(int i = 0 ; i < n; i++){
            cout << "X[" << i+1 << "] = " << x[i] << endl;
        }
    }
    #pragma endregion

    #pragma region GaussJordanElimination
    void SPLClass::SPLGaussJordan(){
        //Deklarasi Persamaan
        int m, n;
        cout << "Masukkan Jumlah Persamaan : ";
        cin >> m;
        cout << "Masukkan Jumlah Variable : ";
        cin >> n;
        //Deklarasi Variable Persamaan
        float a[m][N];
        //Deklarasi Variable Hasil Persamaan
        for(int i = 0; i < m; i++){
            // Menerima Inputan Untuk Persamaan Ke-i
            cout << "Masukkan Persamaan " << i+1 << " : " << endl;
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Variable Ke-i
                cout << "Masukkan Variable x" << j+1 << " : ";
                cin >> a[i][j];
            }
            cout << "Masukkan Hasil Dari Persamaan : ";
            cin >> a[i][n];
        }

        int cek = OBE::OperasiBarisElementer(a, NULL, m, n, -1, NULL);

        if(cek != -1){
            cout << "Berkemungkinan Tidak Bersolusi" << endl;
            if(a[cek][n])
                cout << "Tidak Bisa Di proses" << endl;
            else
                cout << "Memiliki Solusi Banyak" << endl;
            return;
        }

        BackwardPhase(a, m, n);
    }

    float SPLClass::BackwardPhase(float a[][N], int m, int n){
        //Deklarasi Banyak Variable
        float x[n];
        //Perulangan Pada Kolom
        for(int j = n-1; j >= 0; j--){
            //Perulangan Pada Baris dari j-1 hingga Baris 0
            for(int i = j-1; i >= 0; i--){
                float x = a[j][j];
                float y = a[i][j];
                //Perulangan Untuk Memperoleh Baris Eselon Tereduksi 
                for(int k = n+1; k >= i; k--){
                    //Peroleh 0 Jika y/x tidak sama dengan 0
                    if((y/x > 0 ? y/x : -1 * y/x) > 0)
                        a[i][k] -= a[j][k] * y/x;
                }
            }
        }
        cout << "Solusi Dari Persamaan Tersebut Ialah : " << endl;
        for(int i = 0; i < m; i++){
            x[i] = a[i][n]/a[i][i];
            cout << "X[" << i+1 << "] = " << x[i] << endl;
        }
        return -1;
    }
    #pragma endregion