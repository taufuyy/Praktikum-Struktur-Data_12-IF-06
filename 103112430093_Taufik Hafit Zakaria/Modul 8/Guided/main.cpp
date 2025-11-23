//Taufik Hafit Zakaria
//103112430093  
//main.cpp

#include "queue.h" // Hanya include file header, bukan .cpp
#include "queue.cpp"
#include <iostream>
using namespace std;

int main() {
    // Inisialisasi atau membuat queue kosong
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    // Menambahkan 3 elemen pertama ke dalam queue
    cout << "\n enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    // Mengeluarkan 1 elemen dari depan queue
    cout << "\n dequeue 1 elemen" << endl;
    cout << "elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    // Menambahkan 1 elemen baru ke belakang queue
    cout << "\n enqueue 1 elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    // Mengeluarkan 2 elemen lagi dari depan queue
    cout << "\n dequeue 2 elemen" << endl;
    cout << "elemen keluar: " << dequeue(Q) << endl;
    cout << "elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}