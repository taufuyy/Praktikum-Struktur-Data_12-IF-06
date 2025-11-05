//Taufik Hafit Zakaria
//103112430093_12 - IF 06
// File guided

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

bool isEmpty(Node *top){
    return top == nullptr;
}

void push(Node *&top, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
int pop(Node *&top){
    if(isEmpty(top)){
        cout << "Stack kosong, tidak bisa pop!" << endl;
        return 0;
    }
    int poppedData = top->data;
    Node *temp = top;
    top = top->next;

    delete temp;
    return poppedData;
}

void show(Node *top){
    if(isEmpty(top)){
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP -> ";
    Node *temp = top;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *stack = nullptr;
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    cout << "menampilkan isi stack: " << endl;
    show(stack);
    cout << "POP: " << pop(stack) << endl;
    cout << "menampilkan sisa stack: " << endl;
    show(stack);
    return 0;
}

