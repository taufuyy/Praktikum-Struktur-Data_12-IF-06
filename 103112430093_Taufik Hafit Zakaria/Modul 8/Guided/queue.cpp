//Taufik Hafit Zakaria
//103112430093
//queue.cpp

#include "queue.h"
#include <iostream>
using namespace std;

// Prosedur untuk membuat antrian kosong
void createQueue(Queue &Q){
    Q.head = Q.tail = Q.count = 0;
}

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty(Queue Q){
    return Q.count == 0;
}

// Fungsi untuk memeriksa apakah antrian penuh
bool isFull(Queue Q){
    return Q.count == MAX_QUEUE;
}

// Prosedur untuk menambahkan elemen ke dalam antrian
void enqueue(Queue &Q, int x){
    if(!isFull(Q)){
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
        Q.count++;
    } else {
        cout << "Queue penuh!" << endl;
    }
}

// Fungsi untuk menghapus elemen dari antrian
int dequeue(Queue &Q){
    if(!isEmpty(Q)){
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--;
        return x;
    } else {
        cout << "Queue kosong!" << endl;
        return -1;
    }
}

// Prosedur untuk mencetak isi antrian
void printInfo(Queue Q){
    cout << "Queue: [ ";
    if(!isEmpty(Q)){
        int i = Q.head;
        int n = 0;
        while(n < Q.count){
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_QUEUE;
            n++;
        }
    }
    cout << "]" << endl;
}