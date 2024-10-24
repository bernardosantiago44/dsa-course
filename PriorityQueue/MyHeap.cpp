#include "MyHeap.h"

MyHeap::MyHeap() {
    this->values = new int[7];
    this->size = 0;
    this->len = 7;
}

MyHeap::MyHeap(int* valores, int size) {
    this->values = valores;
    this->size = size;
    this->len = size;
}

void MyHeap::imprimir() {
    cout << "arbol size: " << this->size << " len:" << this->len << endl;
    for (int i = 0; i < this->size; i++)
    {
        cout << values[i] << ",";
    }
    cout << endl;
}

void MyHeap::regrowArray() {
    int* temp = this->values;
    this->values = new int[2 * len + 1];
    this->len += len + 1;

    // copiar los datos al nuevo array
    for (int i = 0; i < this->size; i++) {
        (this->values)[i] = temp[i];
    }
    delete[] temp;
}

void MyHeap::push(int n) {
    if (this->size == this->len) {
        this->regrowArray();
    }
    this->values[size++] = n;
}