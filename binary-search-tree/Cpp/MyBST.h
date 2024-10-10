#pragma once

struct MyNodeBST {
    int data;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data, MyNodeBST *left, MyNodeBST *right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    MyNodeBST(int data) : MyNodeBST(data, 0, 0) {};
};

class MyBST {
public:
    int size;
    MyNodeBST* root;

    MyBST();
    int length();
    bool isEmpty();
    bool search(int data);
    bool searchRec(int data);
    bool searchRec(int data, MyNodeBST* current);
    bool insert(int data);
    bool remove();
};