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
    // while (current != nullptr) {
    //     if (current->data == data) {
    //         return true;
    //     }

    //     if (data > current->data) { 
    //         // Derecha
    //         current = current->right;
    //     } else { 
    //         // Izquierda
    //         current = current->left;
    //     }
    // }
    // return false;
    return search(data, current);
}

bool MyBST::insert(int data, MyNodeBST* current) {
    if (data == current->data) return false; // El valor ya esta en el arbol
    MyNodeBST *left, *right;
    left = current->left;
    right = current->right;

    // Caso base: si el actual es una hoka,
    // insertar el valor como una hoja
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

// Con ayuda visual de: https://www.cs.usfca.edu/~galles/visualization/BST.html
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

// Regresa el nodo anterior en orden logico
// (mas a la derecha del subarbol izquierdo)
MyNodeBST* MyBST::getPreviousNode(MyNodeBST* current) {
    current = current->left;
    while (current->right != nullptr && current != nullptr) {
        current = current->right;
    }
    return current;
}

MyNodeBST* MyBST::deleteNode(MyNodeBST* node) {
    if (node == nullptr) return; // Precondicion redundante: El nodo NO es nulo
    
    // Si es un nodo hoja:
    if (node->left == nullptr && node->right == nullptr) {
        // MyNodeBST* temp = node;
        delete node;
        return nullptr;
    }

    // Si solamente tiene un hijo:
        // Preferentemente ir por el izquierdo. Si no hay,
        // se copia el valor del derecho al actual.
    if (node->left == nullptr) {
        MyNodeBST* temp = node;
        MyNodeBST* next = node->right; // node.right!
        node = next;
        delete temp;
    }

    // El nodo tiene 2 hijos:
    MyNodeBST* prev = getPreviousNode(node);
    node->data = prev->data;
    deleteNode(prev); // LLamada recursiva: el delete se hace desde el nodo hoja
}

MyNodeBST* MyBST::remove(int data, MyNodeBST* current) {
    // if (current == nullptr) return false;

    // if (data < current->data) {
    //     // Llamada recursiva: buscar nodo a eliminar en el sub-arbol izquierdo
    //     return remove(data, current->left);
    // } else if (data > current->data) {
    //     // Buscar nodo a eliminar en el sub-arbol derecho
    //     return remove(data, current->right);
    // } else {
    //     // Encontramos el nodo a eliminar
    //     deleteNode(current);
    //     return true;
    // }

    if (current == nullptr) return nullptr;

    if (data < current->data) {
        // Llamada recursiva: buscar nodo a eliminar en el sub-arbol izquierdo
        // Regresa el nodo del nuevo sub-arbol (el mismo si no se eliminó)
        current->right = remove(data, current->right);
    } else if (data > current->data) {
        current->left = remove(data, current->left);
    }
}

bool MyBST::remove(int data) {
    MyNodeBST* current = this->root;
    return remove(data, current);
}

void MyBST::inorder(MyNodeBST* current) {
    if (current == nullptr) return;

    inorder(current->left);
    cout << current->data << ", ";
    inorder(current->right);
}

void MyBST::inorder() {
    MyNodeBST* root = this->root;
    inorder(root);
    cout << endl;
}