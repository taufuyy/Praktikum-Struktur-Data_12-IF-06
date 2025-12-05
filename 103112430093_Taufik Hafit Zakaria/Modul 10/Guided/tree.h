//Taufik Hafit Zakaria
//103112430093
//tree.h

#ifndef TREE_H
#define TREE_H

struct Node {
    int data;
    Node *left, *right;
    int height;
};

class BinaryTree {
    private:
        Node *root;
        Node* insertNode(Node* node, int value);
        Node* deleteNode(Node* node, int value);

        int getHeight(Node* node);
        int getBalance(Node* node);

        Node* rotateRight(Node* node);
        Node* rotateLeft(Node* node);

        Node* minValueNode(Node* node);

        void inorder(Node* node);
        void preorder(Node* node);
        void postorder(Node* node);

    public:
        BinaryTree();
        void insert(int value);
        void deleteValue(int value);
        void update(int oldVal, int newVal);

        void inorder();
        void preorder();
        void postorder();

    };
    #endif

