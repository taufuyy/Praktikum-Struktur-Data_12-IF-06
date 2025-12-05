//Taufik Hafit Zakaria
//103112430093
//mainBstree.cpp

#include <iostream>
#include "bstree.h"
#include "bstree.cpp"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    // ========== SOAL 1 ==========
    cout << "=====================================" << endl;
    cout << "SOAL 1: Implementasi ADT Binary Search Tree" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Memasukkan data: 1, 2, 6, 4, 5, 3, 6, 7" << endl;
    
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);  // Duplikasi, tidak akan dimasukkan
    insertNode(root, 7);
    
    cout << "\nHasil Inorder traversal: ";
    printInorder(root);
    cout << endl;
    
    // ========== SOAL 2 ==========
    cout << "=====================================" << endl;
    cout << "SOAL 2: Fungsi Perhitungan" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Kedalaman       : " << hitungKedalaman(root, 0) << endl;
    cout << "Jumlah Node     : " << hitungNode(root) << endl;
    cout << "Total nilai Node: " << hitungTotal(root) << endl;
    cout << endl;
    
    // ========== SOAL 3 ==========
    cout << "=====================================" << endl;
    cout << "SOAL 3: Print Tree (Pre-order & Post-order)" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Preorder  : ";
    printPreorder(root);
    cout << endl;
    
    cout << "Postorder : ";
    printPostorder(root);
    cout << endl;
    
    return 0;
}