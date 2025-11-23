//Taufik Hafit Zakaria
//103112430093
//queue.h

#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int data);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
