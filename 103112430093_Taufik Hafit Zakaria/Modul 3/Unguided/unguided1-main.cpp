//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include <iostream>
#include "unguided1.h"
#include "unguided1.cpp"
using namespace std;

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Input jumlah mahasiswa (maks 10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 0;
    }

    inputData(mhs, n);
    tampilData(mhs, n);

    return 0;
}