//Taufik Hafit Zakaria
//103112430093_12 - IF 06
// File: stack.cpp

#include <iostream>
#include "stack.h"
using namespace std;

// Membuat stack kosong
void createStack(Stack &S) {
    S.top = 0;
}

// Mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return (S.top == 0);
}

// Menambah elemen ke stack
void push(Stack &S, infotype x) {
    if (S.top == 20) {
        cout << "Stack penuh!" << endl;
        return;
    }
    S.top++;
    S.info[S.top] = x;
}

// Mengambil dan menghapus elemen teratas
infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return -1;
    }
    infotype temp = S.info[S.top];
    S.top--;
    return temp;
}

// Menampilkan isi stack dari TOP ke bawah
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 1; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

// Membalik isi stack
void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }

    S = temp;
}

// Push ascending (urut dari bawah ke atas)
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    // Pindahkan elemen yang lebih besar dari x
    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    // Tambahkan elemen baru
    push(S, x);

    // Kembalikan elemen dari stack sementara
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

// Membaca input angka tanpa spasi (misal: 4729601)
void getInputStream(Stack &S) {
    cout << "Masukkan deretan angka: ";

    string input;
    getline(cin, input);

    for (char c : input) {
        if (isdigit(c)) {
            push(S, c - '0'); // ubah char ke int
        }
    }
}
