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
void MyLinkedList::removeAt(string key) {
    // Precondition: size > 0
    if (size == 0) { 
        return; 
    }

    // List is not empty, continue execution
    // Assert 0 <= pos < size
    MyNodoLL* tmp = head;
    while (tmp->next != nullptr && tmp->next->key != key) { // Stop at one element before the target
        tmp = tmp->next;
    }
    MyNodoLL* toDelete = tmp->next;
    tmp->next = tmp->next->next;
    delete toDelete;
    this->size--;
    
}

// ostream& operator<<(ostream& os, const MyLinkedList& ll) {
//     MyNodoLL* current = ll.head;
//     while (current != nullptr) {
//         os << current->data;
//         if (current->next != nullptr) {
//             os << ", ";
//         }
//         current = current->next;
//     }
//     return os;
// }

// Time complexity: O(n) where n = size
MyLinkedList::~MyLinkedList() {
    MyNodoLL* current = head;
    while (current != nullptr) {
        MyNodoLL* toDelete = current;
        current = current->next;

        delete toDelete;
    }
}