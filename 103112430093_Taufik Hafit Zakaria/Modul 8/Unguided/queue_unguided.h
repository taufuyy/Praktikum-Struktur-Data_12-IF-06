//Taofik Hafit Zakaria
//103112430093
//queue_unguided.h

#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

typedef int infotype;

struct Queue {
    infotype info[5]; 
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif