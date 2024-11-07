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
// O(n)
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
// O(1)
int MyHashTable::getPos(string key) {
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % this->sizeArray;
}

// O(1)
bool MyHashTable::isEmpty() {
    return this->size == 0;
}

// O(1) Caso promedio
// O(n) peor caso (factor de carga >= 0.75)
void MyHashTable::put(string key, int value) {
    int pos = this->getPos(key); // O(1)
    
    this->tabla[pos].insertFirst(key, value); // O(1)
    this->size++;

    if (static_cast<double>(this->size) / static_cast<double>(this->sizeArray) >= 0.75) {
        this->rehash(); // O(n)
    }
}

// O(1) - Sería muy raro que todos los elementos
// cayeran la misma única lista.
int MyHashTable::get(string key) {
    int pos = this->getPos(key); // O(1)

    MyLinkedList& assignedList = this->tabla[pos]; // La Lista donde debería estar el dato
    MyNodoLL* current = assignedList.head;

    // La lista tiene significativamente menos
    // datos que la tabla completa.
    while (current != nullptr) { // O(m)
        if (current->key == key) {
            return current->value;
        } 
        current = current->next;
    }

    throw out_of_range("La llave " + key + " no existe en la tabla.");
}

// O(1) ó O(m) donde m es la cantidad de 
// datos en la lista correspondiente (normalmente constante).
void MyHashTable::remove(string key) {
    int pos = this->getPos(key); // O(1)
    
    MyLinkedList& assignedList = this->tabla[pos];
    
    bool removed = assignedList.removeAt(key); // O(m)
    if (!removed) {
        throw out_of_range("La llave " + key + " no existe en la tabla.");
    }
    this->size--;
}