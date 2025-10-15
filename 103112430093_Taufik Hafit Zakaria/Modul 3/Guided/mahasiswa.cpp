//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include "mahasiswa.h"
#include <iostream>
using namespace std;

void inputMhs(mahasiswa &m){
    cout << "input nama = ";
    cin >> ws;
    cin.getline((m).nim,100);
    cout << "input nilai = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}
float rata2(mahasiswa m){
    return float(m.nilai1+m.nilai2)/2;
}