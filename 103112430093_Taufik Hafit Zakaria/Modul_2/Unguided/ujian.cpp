//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include <iostream>
using namespace std;

float hitungRata(float nilai[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += nilai[i];
    }
    return total / n;
}

void cariNilai(float nilai[], int n, float &maks, float &min) {
    maks = nilai[0];
    min = nilai[0];
    for (int i = 1; i < n; i++) {
        if (nilai[i] > maks) maks = nilai[i];
        if (nilai[i] < min) min = nilai[i];
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah siswa: ";
    cin >> n;
    
    float nilai[n];
    for (int i = 0; i < n; i++) {
        cout << "Nilai siswa ke-" << (i+1) << ": ";
        cin >> nilai[i];
    }
    
    float avg = hitungRata(nilai, n);
    float maks, min;
    cariNilai(nilai, n, maks, min);
    
    cout << "\nRata-rata: " << avg << endl;
    cout << "Nilai tertinggi: " << maks << endl;
    cout << "Nilai terendah: " << min << endl;

    return 0;
}