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
int MyLinkedList::first() {
    if (this->size > 0) {
        return this->head->data;
    } else {
        throw invalid_argument("La lista está vacía.");
    }
}

// Time complexity: O(1)
int MyLinkedList::last() {
    if (this->size > 0) {
        return this->tail->data;
    } else {
        throw invalid_argument("La lista está vacía.");
    }
}

// Time complexity: O(1)
void MyLinkedList::insertFirst(int data) {
    MyNodoLL* newHead = new MyNodoLL(data, head);
    head = newHead;

    if (size == 0) {
        tail = head;
    }
    this->size++;
}

// Time complexity: O(1)
void MyLinkedList::insertLast(int data) {
    MyNodoLL* newTail = new MyNodoLL(data, nullptr);

    if (size == 0) {
        head = newTail;
    } else {
        tail->next = newTail;
    }
    tail = newTail;
    this->size++;
}

// Time complexity: O(n) where n = pos
void MyLinkedList::insertAt(int pos, int data) {
    // Assert: pos >= 0
    if (pos < 0) {
        throw invalid_argument("El índice no puede ser negativo.");
    }
    
    if (pos > size) {
        throw invalid_argument("Índice fuera de rango de la lista.");
    }

    // Position is valid, continue execution
    if (pos == 0) {
        insertFirst(data);
    } else if (pos == size) {
        insertLast(data);
    } else { // Any position between 1 and size - 1
        MyNodoLL* current = head;
        // Start at 1 since we already have the head (first iteration)
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }
        MyNodoLL* newNode = new MyNodoLL(data, current->next);
        current->next = newNode;
        this->size++;
    }
}

// Time complexity: O(n) where n = pos
void MyLinkedList::setAt(int pos, int data) {
    // Assert 0 <= pos < size
    if (pos < 0 || pos >= this->size) {
        throw invalid_argument("La posicion en la lista es invalida.");
    }

    // Position is valid, continue execution
    MyNodoLL* current = this->head;
    for (int i = 0; i < pos; i++) { 
        current = current->next;
    }
    current->data = data;
}

// Time complexity: O(n) where n = pos
int MyLinkedList::getAt(int pos) {
    // Assert 0 <= pos < size
    if (pos < 0 || pos >= size) {
        throw invalid_argument("No se puede obtener el elemento en una posición negativa.");
    }

    // Position is valid, continue execution
    MyNodoLL* current = head;
    for (int i = 1; i <= pos; i++) {
        current = current->next;
    }
    return current->data;
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
void MyLinkedList::removeAt(int pos) {
    // Precondition: size > 0
    if (size == 0) { 
        return; 
    }

    // List is not empty, continue execution
    if (pos == 0) {
        removeFirst();
    } else if (pos == size - 1) {
        removeLast();
    } else {
        // Assert 0 <= pos < size
        if (pos < 0 || pos >= size) {
            throw invalid_argument("Posicion fuera de rango de la lista.");
        }
        MyNodoLL* tmp = head;
        for (int i = 1; i < pos; i++) { // Stop at one element before the target
            tmp = tmp->next;
        }
        MyNodoLL* toDelete = tmp->next;
        tmp->next = tmp->next->next;
        delete toDelete;
        this->size--;
    }
}

ostream& operator<<(ostream& os, const MyLinkedList& ll) {
    MyNodoLL* current = ll.head;
    while (current != nullptr) {
        os << current->data;
        if (current->next != nullptr) {
            os << ", ";
        }
        current = current->next;
    }
    return os;
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