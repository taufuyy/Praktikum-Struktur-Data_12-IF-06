//Taufik Hafit Zakaria
//103112430093  
//mainTree.cpp

#include <iostream>
#include "tree.h"
#include "tree.cpp"
using namespace std;

int main() {
    BinaryTree tree;

    cout << "=== INSERT DATA ===" << endl;
    tree.insert(10);
    tree.insert(15);
    tree.insert(20);
    tree.insert(30);
    tree.insert(35);
    tree.insert(40);
    tree.insert(50);

    cout << "Data yang diinsert:10, 15, 20, 30, 35, 40, 50" << endl;
    
    cout << "\nTrasversal setelah Insert:" <<endl;
    cout << "Inorder: "; tree.inorder();
    cout << "Preorder: "; tree.preorder();
    cout << "Postorder: "; tree.postorder();

    cout << "\n=== UPDATE DATA ===" << endl;
    cout << "Update (20 -> 25)" << endl;
    cout << "inorder    : "; tree.inorder();

    tree.update(20, 25);

    cout << "Setelah Update (20 -> 25):" << endl;
    cout << "inorder    : "; tree.inorder();

    cout << "\n=== DELETE DATA ===" << endl;
    cout << "Sebelum delate (hapus sebtree dengan root 30):" << endl;
    cout << "inorder    : "; tree.inorder();

    tree.deleteValue(30);
    cout << "Setelah delete (hapus sebtree dengan root 30):" << endl;
    cout << "inorder    : "; tree.inorder();
    
    return 0;
}