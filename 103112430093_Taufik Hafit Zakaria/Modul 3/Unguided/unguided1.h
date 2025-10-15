//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#ifndef UNGUIDED1_H_INCLUDED
#define UNGUIDED1_H_INCLUDED

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas);
void inputData(Mahasiswa mhs[], int n);
void tampilData(Mahasiswa mhs[], int n);

#endif 