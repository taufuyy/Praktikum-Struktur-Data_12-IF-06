//Taufik Hafit Zakaria
//103112430093_12 - IF 06
//singlylist.cpp

#include "singlylist.h"

// Membuat sebuah list baru yang masih kosong
void createList(list &L){
    L.first = Nil;
}

// Mengalokasikan memori untuk sebuah elemen baru
// dan mengisi elemen tersebut dengan data (X)
address alokasi(infotype X){
    address P = new elmlist;
    P->info = X;
    P->next = Nil;
    return P;
}

// Menghapus atau membebaskan memori dari sebuah elemen
void dealokasi(address &P){
    delete P;
}

// Menambahkan sebuah elemen baru di awal list
void insertFirst(list &L, address P){
    P->next = L.first;
    L.first = P;
}

// Menambahkan sebuah elemen baru di akhir list
void insertLast(list &L, address P){
    if(L.first == Nil){
        // Jika list masih kosong, elemen baru menjadi elemen pertama
        insertFirst(L, P);
    } else {
        // Jika list sudah ada isinya, cari elemen terakhir
        address Last = L.first;
        while (Last->next != Nil){
            Last = Last->next;
        }
        // Sambungkan elemen terakhir dengan elemen baru
        Last->next = P;
    }
}

// Menampilkan semua isi data dari setiap elemen di list
void printInfo(list L){
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}
