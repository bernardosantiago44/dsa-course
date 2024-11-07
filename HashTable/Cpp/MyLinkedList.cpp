// Bernardo Santiago Marín
// A01638915
#include "MyLinkedList.h"

MyLinkedList::MyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// Time complexity: O(1)
int MyLinkedList::length() {
    return this->size;
}

// Time complexity: O(1)
bool MyLinkedList::isEmpty() {
    return this->size == 0;
}

// Time complexity: O(1)
void MyLinkedList::insertFirst(string key, int value) {
    MyNodoLL* newHead = new MyNodoLL(key, value, head);
    this->head = newHead;

    if (size == 0) {
        tail = head;
    }
    this->size++;
}

// Time complexity: O(n) 
int MyLinkedList::getAt(string key) {
    // Buscar el elemento con la llave 
    MyNodoLL* current = head;
    while (current->key != key) {
        current = current->next;
    }
    
    // regresar su valor
    return current->value;
}

// O(1)
void MyLinkedList::removeFirst() {
    // Precondition: size > 0
    if (size == 0) {
        throw invalid_argument("La lista está vacía.");
    } else {
        MyNodoLL* tmp = head;
        this->head = head->next;
        delete tmp;
        this->size--;
        if (size == 0) {
            tail = nullptr;
        }
    }
}

// Time complexity: O(n) where n = size
void MyLinkedList::removeLast() {
    // Precondition: size > 0
    if (size == 0) { 
        return; 
    }

    // List is not empty, continue execution
    MyNodoLL* tmp = head;
    for (int i = 1; i < this->size - 1; i++) { // Stop at the second to last element
        tmp = tmp->next;
    }
    delete tmp->next;
    tail = tmp;
    tmp->next = nullptr;
    this->size--;
    if (size == 0) {
        head = nullptr;
    }
}

// Time complexity: O(n) where n = pos
bool MyLinkedList::removeAt(string key) {
    if (this->size == 0) { 
        return false; // La lista está vacía 
    }

    MyNodoLL* previous = nullptr;
    MyNodoLL* current = this->head; 
    while (current->key != key) {
        previous = current;
        current = current->next;
    }
    
    if (current == nullptr) {
        // No se encontró el nodo a eliminar.
        return false;
    } else if (current == this->head) {
        this->head = current->next;
    }
    else if (current == this->tail) {
        // Si el nodo a eliminar es tail, 
        // reasignamos tail y desenlazamos el anterior.
        this->tail = previous;
        previous->next = nullptr;
    } else {
        // Si el nodo a eliminar está en medio, solo 
        // queda desenlazar y eliminar.
        previous->next = current->next;
    }

    delete current;
    this->size--;
    return true;
}

// Time complexity: O(n) where n = size
MyLinkedList::~MyLinkedList() {
    MyNodoLL* current = head;
    while (current != nullptr) {
        MyNodoLL* toDelete = current;
        current = current->next;

        delete toDelete;
    }
}