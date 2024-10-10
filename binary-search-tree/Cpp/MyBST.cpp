#include "MyBST.h"

MyBST::MyBST() {
    this->size = 0;
    this->root = 0;
}

int MyBST::length() {
    return this->size;
}

bool MyBST::isEmpty() {
    return this->size == 0;
}

bool MyBST::search(int data) {
    MyNodeBST* current = this->root;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }

        if (data > current->data) { 
            // Derecha
            current = current->right;
        } else { 
            // Izquierda
            current = current->left;
        }
    }
    return false;
}