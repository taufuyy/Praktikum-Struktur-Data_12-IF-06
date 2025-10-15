//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include <iostream>
#include "unguided2.h"
#include "unguided2.cpp"
using namespace std;

int main()
{
    string namapel = "Struktur Data";
    string kodemapel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodemapel);
    tampil_pelajaran(pel);

    return 0;
}