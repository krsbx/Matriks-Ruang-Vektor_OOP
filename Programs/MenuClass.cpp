#include "MenuClass.h"
#include "CramerClass.h"
#include "DeterminanClass.h"
#include "SPLClass.h"
#include "InverseClass.h"
#include "InverseMethod.h"
#include<iostream>
using namespace std;

    void MenuClass::Menu(){
        cout << "Pilih Aksi : " << endl;
        cout << "1. Sistem Persamaan Linier n Variable" << endl; //Completed
        cout << "2. Menghitung Determinan" << endl; //Completed
        cout << "3. Menentukan Matriks Balikan" << endl; //Completed
        cout << "4. Keluar" << endl;
        cout << "Masukkan Pilihan : ";
        int i;
        cin >> i;
        switch(i){
            case 1:
                Pertama();
            break;
            case 2:
                Kedua();
            break;
            case 3:
                Ketiga();
            break;
        }
    }
    void MenuClass::Pertama(){
        cout << "Pilih Metode : " << endl;
        cout << "1. Eliminasi Gauss" << endl; //On Going
        cout << "2. Eliminasi Gauss-Jordan" << endl; //On Going
        cout << "3. Metode Matriks Balikan" << endl; //On Going
        cout << "4. Kaidah Cramer" << endl; //Completed
        cout << "5. Kembali Ke Menu Sebelumnya" << endl; //Completed
        cout << "Masukkan Pilihan : ";
        int i;
        cin >> i;
        switch(i){
            SPLClass pertama;
            case 1:
                pertama.SPLGauss();
            break;
            case 2:
                pertama.SPLGaussJordan();
            break;
            case 3:
                InverseMethod inverse;
                inverse.InverseSPL();
            break;
            case 4:
                CramerClass cramer;
                cramer.Cramer();
            break;
            case 5:
                Menu();
            break;
        }
    }
    void MenuClass::Kedua(){
        cout << "Pilih Metode : " << endl;
        cout << "1. Reduksi Baris" << endl; //Completed
        cout << "2. Ekspansi Kofaktor" << endl; //Completed
        cout << "3. Kembali Ke Menu Sebelumnya" << endl; //Completed
        cout << "Masukkan Pilihan : ";
        int i;
        cin >> i;
        switch(i){
            DeterminanClass deter;
            case 1:
                deter.ReduksiDeterminan();
            break;
            case 2:
                deter.EkspansiKofaktor();
            break;
            case 3:
                Menu();
            break;
        }
    }
    void MenuClass::Ketiga(){
        InverseClass inverse;
        inverse.Inverse();
    }
