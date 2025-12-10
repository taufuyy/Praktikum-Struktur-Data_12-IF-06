//Taufik Hafit Zakaria
//103112430093
//main.cpp

#include "circularlist.h"
#include "circularlist.cpp"
#include <iostream>
using namespace std;

address createData(string nama, string nim, char jk, float ipk)
{
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jk;
    x.ipk = ipk;
    return alokasi(x);
}

void sortList(List &L) {
    if (L.first == Nil) {
        return;
    }
    
    address P = L.first;
    address Q;
    infotype temp;
    
    do {
        Q = P->next;
        while (Q != L.first) {
            if (P->info.nim > Q->info.nim) {
                temp = P->info;
                P->info = Q->info;
                Q->info = temp;
            }
            Q = Q->next;
        }
        P = P->next;
    } while (P->next != L.first);
}

int main()
{
    List L;
    address P1 = Nil;
    address P2 = Nil;
    infotype x;
    
    createList(L);
    
    cout << "coba insert first, last, dan after" << endl;
    
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);
    
    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);
    
    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);
    
    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);
    
    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);
    
    x.nim = "07";
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, P1, P2);
    
    x.nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'l', 3.3);
    insertAfter(L, P1, P2);
    
    x.nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, P1, P2);
    
    sortList(L);
    
    printInfo(L);
    
    return 0;
}