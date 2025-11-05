//Taufik Hafit Zakaria
//103112430093_12 - IF 06
// File: stack.h

#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

// Membuat stack kosong
void createStack(Stack &S);

// Menambah elemen ke stack
void push(Stack &S, infotype x);

// Menghapus elemen dari stack dan mengembalikannya
infotype pop(Stack &S);

// Menampilkan isi stack dari TOP ke bawah
void printInfo(Stack S);

// Membalik urutan elemen dalam stack
void balikStack(Stack &S);

// Menyisipkan elemen agar stack berurutan ascending
void pushAscending(Stack &S, infotype x);

// Membaca input deretan angka tanpa spasi hingga Enter
void getInputStream(Stack &S);

// Mengecek apakah stack kosong
bool isEmpty(Stack S);

#endif
