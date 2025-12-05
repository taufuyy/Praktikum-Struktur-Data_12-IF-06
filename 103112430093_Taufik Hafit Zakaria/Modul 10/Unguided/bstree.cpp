//Taufik Hafit Zakaria
//103112430093
//bstree.cpp

#include "bstree.h"
#include <iostream>
using namespace std;

// Fungsi alokasi untuk membuat node baru
address alokasi(infotype x) {
    address newNode = new Node;
    if (newNode != Nil) {
        newNode->info = x;
        newNode->left = Nil;
        newNode->right = Nil;
    }
    return newNode;
}

// Fungsi insert node ke BST secara rekursif
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
        // Jika x == root->info, tidak insert (menghindari duplikasi)
    }
}

// Fungsi untuk mencari node dengan nilai tertentu
address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    
    if (root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorderRecursive(address root, bool &isFirst) {
    if (root != Nil) {
        printInorderRecursive(root->left, isFirst);

        if (isFirst) {
            isFirst = false;
        } else {
            cout << " - ";
        }
        cout << root->info;

        printInorderRecursive(root->right, isFirst);
    }
}

// Fungsi traversal Inorder: Left - Root - Right
void printInorder(address root) {
    bool isFirst = true;
    printInorderRecursive(root, isFirst);
}

// Fungsi traversal Preorder: Root - Left - Right
void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Fungsi traversal Postorder: Left - Right - Root
void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " ";
    }
}

// Fungsi untuk menghitung jumlah node dalam BST
int hitungNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

// Fungsi untuk menghitung total nilai semua node
int hitungTotal(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

// Fungsi rekursif untuk menghitung kedalaman maksimal tree
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }
    
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    
    return (kiri > kanan) ? kiri : kanan;
}