//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include <iostream>
#include "unguided2.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodemapel)
{
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodemapel;
    return pel;
}

void tampil_pelajaran(pelajaran pel)
{
    cout << "Nama Mata Pelajaran: " << pel.namaMapel << endl;
    cout << "Nilai: " << pel.kodeMapel << endl;
}