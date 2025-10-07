//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int JUMLAH_MAHASISWA = 5;
    const int JUMLAH_MATA_KULIAH = 3;
    
    string namaMahasiswa[JUMLAH_MAHASISWA];
    float nilaiMahasiswa[JUMLAH_MAHASISWA][JUMLAH_MATA_KULIAH];
    float rataRata[JUMLAH_MAHASISWA];
    
    cout << "=== INPUT DATA NILAI MAHASISWA ===\n";
    for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
        cout << "\nMahasiswa ke-" << (i + 1) << ":\n";
        cout << "Nama: ";
    
        getline(cin >> ws, namaMahasiswa[i]);
        cout << "Masukkan nilai 3 mata kuliah:\n";
        float totalNilai = 0;
        for (int j = 0; j < JUMLAH_MATA_KULIAH; j++) {
            cout << "  Mata kuliah " << (j + 1) << ": ";
            cin >> nilaiMahasiswa[i][j];
            totalNilai += nilaiMahasiswa[i][j];
        }
        
        rataRata[i] = totalNilai / JUMLAH_MATA_KULIAH;
    }
    
    int indeksTerbaik = 0;
    for (int i = 1; i < JUMLAH_MAHASISWA; i++) {
        if (rataRata[i] > rataRata[indeksTerbaik]) {
            indeksTerbaik = i;
        }
    }
    
    cout << "\n\n=== HASIL NILAI MAHASISWA ===\n";
    cout << "===========================================================\n";
    cout << left << setw(12) << "Nama" 
         << setw(8) << "MK1" 
         << setw(8) << "MK2" 
         << setw(8) << "MK3" 
         << setw(12) << "Rata-rata" 
         << "Keterangan\n";
    cout << "===========================================================\n";
    
    for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
        cout << left << setw(12) << namaMahasiswa[i];
        
        for (int j = 0; j < JUMLAH_MATA_KULIAH; j++) {
            cout << setw(8) << fixed << setprecision(1) << nilaiMahasiswa[i][j];
        }
        
        cout << setw(12) << fixed << setprecision(2) << rataRata[i];
        
        if (i == indeksTerbaik) {
            cout << "TERBAIK";
        }
        cout << endl;
    }
    
    cout << "\n=== MAHASISWA TERBAIK ===\n";
    cout << "Nama: " << namaMahasiswa[indeksTerbaik] << endl;
    cout << "Rata-rata nilai: " << fixed << setprecision(2) << rataRata[indeksTerbaik] << endl;
    
    return 0;
}