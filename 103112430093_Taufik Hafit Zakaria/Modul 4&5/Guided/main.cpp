//Taufik Hafit Zakaria
//103112430093_12 - IF 06
//main.cpp

#include <iostream>
#include <cstdlib>
#include "singlylist.h"
#include "singlylist.cpp"

using namespace std;

// Fungsi utama program
int main() {
    // Deklarasi variabel list L dan address P
    list L;
    address P;

    // 1. Membuat list kosong
    createList(L);
    cout << "membuat list menggunakan insertiLast..."<<endl;

    // 2. Mengisi list dengan beberapa elemen menggunakan insertLast
    // Alokasi memori dan masukkan nilai 9 ke akhir list
    P = alokasi(9);
    insertLast(L, P);
    // Alokasi memori dan masukkan nilai 12 ke akhir list
    P = alokasi(12);
    insertLast(L, P);
    // Alokasi memori dan masukkan nilai 8 ke akhir list
    P = alokasi(8);
    insertLast(L, P);
    // Alokasi memori dan masukkan nilai 0 ke akhir list
    P = alokasi(0);
    insertLast(L, P);
    // Alokasi memori dan masukkan nilai 2 ke akhir list
    P = alokasi(2);
    insertLast(L, P);

    // 3. Menampilkan seluruh isi list
    cout << "isi list sekarang adalah: "; 
    printInfo(L);

    // Menjeda program sebelum ditutup (khusus Windows)
    system("pause");
    return 0;
}