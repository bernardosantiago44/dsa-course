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

// Recursive implementarion of search
bool MyBST::search(int data, MyNodeBST* current) {
    if (current == nullptr) return false;
    if (current->data == data) {
        return true;
    } else if (data < current->data) {
        // Left of BST
        return search(data, current->left);
    } else {
        // Right of BST
        return search(data, current->right);
    }
}

// Preparation of the recursive function
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

bool MyBST::insert(int data, MyNodeBST* current) {
    if (data == current->data) return false; // The value was already in the tree
    MyNodeBST *left, *right;
    left = current->left;
    right = current->right;

    // Base case: Current is a leaf
    if (data < current->data && left == nullptr) {
        current->left = new MyNodeBST(data);
        this->size++;
        return true;
    } else if (data > current->data && right == nullptr) {
        current->right = new MyNodeBST(data);
        this->size++;
        return true;
    }

    if (data < current->data) {
        return insert(data, current->left);
    } else {
        return insert(data, current->right);
    }
}

// Created with help of the online tool https://www.cs.usfca.edu/~galles/visualization/BST.html
bool MyBST::insert(int data) {
    MyNodeBST* current = this->root;
    // If the tree is empty, create a root
    if (this->size == 0) {
        this->root = new MyNodeBST(data);
        this->size++;
        return true;
    } 

    return insert(data, this->root);
}