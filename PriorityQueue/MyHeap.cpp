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

    int current = this->getParentIndex(size - 1);
    for (int current = this->getParentIndex(size - 1); current >= 0; current--) {
        this->heapifyDOWN(current);
    }
}

void MyHeap::imprimir() {
    cout << "arbol size: " << this->size << " len: " << this->len << endl;
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

// Caso promedio (el arreglo no está lleno): O(log(n))
// Peor caso (el arreglo está lleno): O(m) donde m es size.
void MyHeap::push(int n) {
    if (this->size == this->len) {
        this->regrowArray();
    }
    this->values[size++] = n;
    this->heapifyUP();
}

// En el peor de los casos (cuando el valor a insertar es máximo),
// Complejidad temporal: O(log(n))
void MyHeap::heapifyUP() {
    int current = this->size - 1; // Ultimo elemento insertado
    int parent = this->getParentIndex(current);

    // Comparar el actual con su padre, e intercambiar si este es mayor
    while (current > 0 && this->values[current] > this->values[parent]) {
        swap(this->values[current], this->values[parent]);
        current = parent;
        parent = this->getParentIndex(current);
    }
}

// Peor caso: El nodo del principio es el menor valor
// O(log(n))
void MyHeap::heapifyDOWN(int current) {
    int leftChild = this->getLeftChildIndex(current); // O(1)
    int rightChild = this->getRightChildIndex(current); // O(1)
    int greatest = this->getGreatestNode(leftChild, rightChild); // O(1)
    while (current != -1 && greatest != -1) { // Up to O(log(n))
        if (this->values[current] < this->values[greatest]) {
            swap(this->values[current], this->values[greatest]);
        }
        current = greatest;
        leftChild = this->getLeftChildIndex(current);
        rightChild = this->getRightChildIndex(current);
        greatest = this->getGreatestNode(leftChild, rightChild);
    }
}

int MyHeap::getGreatestNode(int left, int right) const {
    if (left == -1 && right == -1) {
        return -1;
    } else if (left == -1) {
        return right;
    } else if (right == -1) {
        return left;
    } else {
        int valueLeft = this->values[left];
        int valueRight = this->values[right];
        if (valueRight > valueLeft) {
            return right;
        } else {
            return left;
        }
    }
}

bool MyHeap::isEmpty() {
    return this->size == 0;
}

int MyHeap::top() {
    if (this->size < 1) {
        cerr << "The queue is empty." << endl;
    } 
    return this->values[0];
}

void MyHeap::pop() {
    if (this->size > 0) {
        // Set the last element at the front
        this->values[0] = this->values[--size];
        this->heapifyDOWN(0); // Heapify hacia abajo desde la raiz
    }
}

// O(1)
// Regresa el índice del elemento padre, o -1 si no existe.
int MyHeap::getParentIndex(int current) const {
    if (current <= 0 || current >= this->size) return -1;
    return (current - 1) / 2;
}

// O(1)
// Regresa el índice del elemento hijo izquierdo, o -1 si no existe.
int MyHeap::getLeftChildIndex(int current) const {
    if (current < 0 || current >= this->size) return -1;
    int left = current * 2 + 1;
    if (left < this->size) return left;
    return -1;
}

// O(1)
// Regresa el índice del elemento hijo derecho, o -1 si no existe.
int MyHeap::getRightChildIndex(int current) const {
    if (current < 0 || current >= this->size) return -1;
    int right = current * 2 + 2;
    if (right < this->size) return right;
    return -1;
}

// O(1)
int MyHeap::length() {
    /* Creo que conceptualmente, y para evitar errores logicos, 
    es mejor definir capacity como la capacidad máxima de la lista, y 
    length para contabilizar los elementos almacenados; o mantener
    congruencia entre los nombres de atributos y sus getters.   
    */
    return this->size;
}