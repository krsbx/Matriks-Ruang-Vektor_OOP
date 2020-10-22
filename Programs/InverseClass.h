#ifndef INVERSECLASS_H
#define INVERSECLASS_H
#include <iostream>
#include "Operasi.h"
using namespace std;

class InverseClass{
    public:
        void InverseKeyboard();
        void Inverse(float a[][N], int n);
        static void BentukIdentitas(float a[][N], int n);
        static void AddIdentitas(float a[][N], int n, string nama);
};
#endif