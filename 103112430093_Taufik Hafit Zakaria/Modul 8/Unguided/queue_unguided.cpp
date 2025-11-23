//Taofik Hafit Zakaria
//103112430093
//queue_unguided.cpp

#include <iostream>
#include "queue_unguided.h"

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == 0);
}

bool isFullQueue(Queue Q) {
    //return (Q.tail == 5);                    // soal 1
    
    //return (Q.tail == 5 && Q.head == 1);  // soal 2
    
     if (isEmptyQueue(Q)) {                // soal 3
         return false;
     }
     int nextTail;
     if (Q.tail == 5) {
         nextTail = 1;
     } else {
         nextTail = Q.tail + 1;
     }
     return (nextTail == Q.head);
}
void enqueue(Queue &Q, infotype x) {
    // soal 1
    /*if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 1;
            Q.tail = 1;
            Q.info[Q.tail - 1] = x; 
        } else {
            Q.tail++;
            Q.info[Q.tail - 1] = x;
        }
    }*/
    
     //soal 2
    /* if (isFullQueue(Q)) {
         cout << "Queue penuh!" << endl;
     } else {
         if (isEmptyQueue(Q)) {
             Q.head = 1;
             Q.tail = 1;
             Q.info[Q.tail - 1] = x;
         } else {
             // Cek apakah perlu geser elemen
             if (Q.tail == 5 && Q.head > 1) {
                 // Geser semua elemen ke depan
                 int j = 1;
                 for (int i = Q.head; i <= Q.tail; i++) {
                     Q.info[j - 1] = Q.info[i - 1];
                     j++;
                 }
                 Q.tail = Q.tail - Q.head + 2;
                 Q.head = 1;
                 Q.info[Q.tail - 1] = x;
             } else {
                 Q.tail++;
                 Q.info[Q.tail - 1] = x;
             }
         }
     }*/
    
     //soal 3
     if (isFullQueue(Q)) {
         cout << "Queue penuh!" << endl;
     } else {
         if (isEmptyQueue(Q)) {
             Q.head = 1;
             Q.tail = 1;
             Q.info[Q.tail - 1] = x;
         } else {
             // Tail bergerak circular
             if (Q.tail == 5) {
                 Q.tail = 1;
             } else {
                 Q.tail++;
             }
             Q.info[Q.tail - 1] = x;
         }
     }
}

infotype dequeue(Queue &Q) {
    
    //soal 1
    /*infotype x;
    
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        x = Q.info[Q.head - 1];
        
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            // Geser semua elemen ke depan
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i - 1] = Q.info[i];
            }
            Q.tail--;
        }
        
        return x;
    }*/
    
    // soal 2
    /* infotype x;
    
     if (isEmptyQueue(Q)) {
         cout << "Queue kosong!" << endl;
         return -1;
     } else {
         x = Q.info[Q.head - 1];
        
         if (Q.head == Q.tail) {
             createQueue(Q);
         } else {
             // Head bergerak maju (TIDAK ada pergeseran)
             Q.head++;
         }
        
         return x;
     }*/
    
    // soal 3
     infotype x;
     if (isEmptyQueue(Q)) {
         cout << "Queue kosong!" << endl;
         return -1;
     } else {
         x = Q.info[Q.head - 1];
  
         if (Q.head == Q.tail) {
             createQueue(Q);
         } else {
             // Head bergerak circular
             if (Q.head == 5) {
                 Q.head = 1;
             } else {
                 Q.head++;
             }
         }
  
         return x;
     }
}


void printInfo(Queue Q) {
    
    //soal 1 & 2
    /*if (isEmptyQueue(Q)) {
        cout << " " << Q.head - 1 << " - " << Q.tail - 1 << " \t | empty queue" << endl;
    } else {
        cout << " " << Q.head - 1 << " - " << Q.tail - 1 << " \t | ";
        
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i - 1];
            if (i < Q.tail) {
                cout << " ";
            }
        }
        cout << endl;
    }*/
    
    // soal 3
     if (isEmptyQueue(Q)) {
         cout << " " << Q.head - 1 << " - " << Q.tail - 1 << " \t | empty queue" << endl;
     } else {
         cout << " " << Q.head - 1 << " - " << Q.tail - 1 << " \t | ";
  
         // Print dengan konsep circular
         int i = Q.head;
         bool first = true;
  
         while (true) {
             if (!first) cout << " ";
             cout << Q.info[i - 1];
             first = false;
      
             if (i == Q.tail) break;
      
             // Bergerak circular
             if (i == 5) {
                 i = 1;
             } else {
                 i++;
             }
         }
         cout << endl;
     }
}