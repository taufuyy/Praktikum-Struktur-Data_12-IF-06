//Taufik Hafit Zakaria
//103112430093_12 - IF 06
//list.h

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#define Nil NULL
using namespace std;  
/*deklarasi record dan struktur data list*/ 
typedef int infotype; 
typedef struct elmlist *address; 
struct elmlist {    
    infotype info;    
    address next; 
}; 
struct list{    
    address first; 
}; 

void createList(list &L);
address alokasi(infotype X);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void printInfo(list L);

#endif
