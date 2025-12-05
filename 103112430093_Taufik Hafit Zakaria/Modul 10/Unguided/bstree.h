//Taufik Hafit Zakaria
//103112430093
//bstree.h

#ifndef BSTREE_H
#define BSTREE_H

#define Nil nullptr

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

typedef address BinTree;

// Fungsi alokasi
address alokasi(infotype x);

// Fungsi insert
void insertNode(address &root, infotype x);

// Fungsi find
address findNode(infotype x, address root);

// Fungsi traversal
void printInorder(address root);
void printPreorder(address root);
void printPostorder(address root);

// Fungsi untuk Soal 2
int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);

#endif