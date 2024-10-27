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

void MyHeap::heapifyDOWN() {
    int current = 0;
    int greatest = -1;
    do {
        int leftChild = this->getLeftChildIndex(current);
        int rightChild = this->getRightChildIndex(current);

        // Seleccionar el hijo más grande
        if (rightChild != -1) {
            greatest = rightChild;
        } else {
            greatest = leftChild;
        }

    } while (current != -1 && greatest != -1)

    while (current < this->size) {
        if (this->values[current] < this->values[leftChild]) {
            swap(this->values[current], this->values[leftChild]);
            current = leftChild
        } else if (this->values[current] < this->values[rightChild])
    }
}

void MyHeap::pop() {
    if (this->size > 0) {
        // Set the last element at the front
        this->values[0] = this->values[--size];
        this->heapifyDOWN();
    }
}

int MyHeap::removeElementAt(int pos) {
    int leftChild = this->getLeftChildIndex(pos);
    int rightChild = this->getRightChildIndex(pos);
    
    // Condición de paro: El nodo no tiene hijo izquierdo ni derecho
    if (leftChild == -1 && rightChild == -1) {
        return this->values[pos];
    }

    int valueToRemove = this->values[pos];
    if (rightChild == -1) {
        this->values[pos] = removeElementAt(leftChild);
    } else if (leftChild == -1) {
        this->values[pos] = removeElementAt(rightChild);
    } else if (this->values[leftChild] > this->values[rightChild]) {
        this->values[pos] = removeElementAt(leftChild);
    } else {
        this->values[pos] = removeElementAt(leftChild);
    }
    return valueToRemove;
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
    es mejor definir size como la capacidad máxima de la lista, y 
    length para contabilizar los elementos almacenados; o mantener
    congruencia entre los nombres de atributos y sus getters.   
    */
    return this->size;
}