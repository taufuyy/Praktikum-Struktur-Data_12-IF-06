//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include <string>
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
using namespace std;

struct pelajaran
{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodemapel);

void tampil_pelajaran(pelajaran pel);
#endif