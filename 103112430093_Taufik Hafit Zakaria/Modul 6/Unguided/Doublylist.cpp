//Taufik Hafit Zakaria
//103112430093_12 - IF 06
//Doublylist.cpp
#include "Doublylist.h"

// Membuat list kosong
void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

// Alokasi elemen baru
address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

// Dealokasi elemen
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Menampilkan isi list
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << "No Polisi  : " << P->info.nopol << endl;
        cout << "Warna      : " << P->info.warna << endl;
        cout << "Tahun      : " << P->info.thnBuat << endl;
        cout << "------------------------" << endl;
        P = P->next;
    }
}

// Insert di bagian akhir list
void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

// Mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    }
}

// Menghapus elemen setelah elemen tertentu
void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}
