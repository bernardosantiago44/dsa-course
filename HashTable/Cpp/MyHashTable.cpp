#include "MyHashTable.h"
#include <cmath>
#include <functional>

MyHashTable::MyHashTable() {
    this->size = 0;
    this->sizeArray = 11;
    this->tabla = new MyLinkedList[this->sizeArray];
}

// Eliminar cada una de las listas enlazadas. Posteriormente
// eliminar el array.
MyHashTable::~MyHashTable() {
    // Eliminar las listas enlazadas, una por una
    delete[] this->tabla;
    this->tabla = nullptr;
}

// Redistribuye los elementos del array cuando
// el factor de carga excede de 0.75
void MyHashTable::rehash() {
    // 2 * sizeA + 1
    MyLinkedList* oldTable = this->tabla;
    int oldSize = this->sizeArray;
    this->sizeArray = 2 * sizeArray + 1;
    this->tabla = new MyLinkedList[this->sizeArray];
    this->size = 0; // El put automáticamente incrementa el size

    // Recorrer el array para reacomodar todos los elementos
    for (int i = 0; i < oldSize; i++) {
        // Acceder por referencia para evitar llamar al destructor prematuramente
        // (evita dangling pointers)
        const MyLinkedList& currentList = oldTable[i]; 
        MyNodoLL* currentNode = currentList.head;

        while (currentNode != nullptr) {
            this->put(currentNode->key, currentNode->value);
            currentNode = currentNode->next;
        }
    }
    delete[] oldTable;
}

// Regresa la posición que le corresponde a la clave
int MyHashTable::getPos(string key) {
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % this->sizeArray;
}

bool MyHashTable::isEmpty() {
    return this->size == 0;
}

void MyHashTable::put(string key, int value) {
    int pos = this->getPos(key);
    
    this->tabla[pos].insertFirst(key, value);
    this->size++;

    if (static_cast<double>(this->size) / static_cast<double>(this->sizeArray) >= 0.75) {
        this->rehash();
    }
}

int MyHashTable::get(string key) {
    int pos = this->getPos(key);

    MyLinkedList& assignedList = this->tabla[pos]; // La Lista donde debería estar el dato
    MyNodoLL* current = assignedList.head;

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        } 
        current = current->next;
    }

    throw out_of_range("La llave " + key + " no existe en la tabla.");
}

void MyHashTable::remove(string key) {
    int pos = this->getPos(key);
    
    MyLinkedList& assignedList = this->tabla[pos];
    
    bool removed = assignedList.removeAt(key);
    if (!removed) {
        throw out_of_range("La llave " + key + " no existe en la tabla.");
    }
    this->size--;
}