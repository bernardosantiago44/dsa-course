#include "MyLinkedList.h"

MyLinkedList::MyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

int MyLinkedList::length() {
    return this->size;
}

bool MyLinkedList::isEmpty() {
    return this->size == 0;
}

int MyLinkedList::first() {
    if (this->size > 0) {
        return this->head->data;
    } else {
        throw invalid_argument("La lista está vacía.");
    }
}

int MyLinkedList::last() {
    if (this->size > 0) {
        return this->tail->data;
    } else {
        throw invalid_argument("La lista está vacía.");
    }
}

void MyLinkedList::insertFirst(int data) {
    MyNodoLL* newHead = new MyNodoLL(data, head);
    head = newHead;

    if (size == 0) {
        tail = head;
    }
    this->size++;
}

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

void MyLinkedList::insertAt(int pos, int data) {
    if (pos < 0) {
        throw invalid_argument("El índice no puede ser negativo.");
    }
    
    if (pos > size) {
        throw invalid_argument("Índice fuera de rango de la lista.");
    }

    if (pos == 0) {
        insertFirst(data);
    } else if (pos == size) {
        insertLast(data);
    } else { // Cualquier posición entre (0, size)
        MyNodoLL* current = head;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }
        MyNodoLL* newNode = new MyNodoLL(data, current->next);
        current->next = newNode;
        this->size++;
    }
}

void MyLinkedList::setAt(int pos, int data) {
    if (pos < 0 || pos >= this->size) {
        throw invalid_argument("La posicion en la lista es invalida.");
    }

    MyNodoLL* current = this->head;
    for (int i = 0; i < pos; i++) { 
        current = current->next;
    }
    current->data = data;
}
int MyLinkedList::getAt(int pos) {
    if (pos < 0) {
        throw invalid_argument("No se puede obtener el elemento en una posición negativa.");
    }
    if (pos >= size) {
        throw invalid_argument("No se puede obtener el elemento en la posición pos en una lista de tamanio size");
    }
    MyNodoLL* current = head;
    for (int i = 1; i <= pos; i++) {
        current = current->next;
    }
    return current->data;
}

// O(1)
void MyLinkedList::removeFirst() {
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

// O(n)
void MyLinkedList::removeLast() {
    if (size == 0) { 
        return; 
    }
    MyNodoLL* tmp = head;
    for (int i = 1; i < this->size - 1; i++) {
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

void MyLinkedList::removeAt(int pos) {
    if (size == 0) { 
        return; 
    }
    if (pos == 0) {
        removeFirst();
    } else if (pos == size - 1) {
        removeLast();
    } else {
        if (pos < 0 || pos >= size) {
            throw invalid_argument("Posicion fuera de rango de la lista.");
        }
        MyNodoLL* tmp = head;
        for (int i = 1; i < pos; i++) {
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

MyLinkedList::~MyLinkedList() {
    MyNodoLL* current = head;
    while (current != nullptr) {
        MyNodoLL* toDelete = current;
        current = current->next;

        delete toDelete;
    }
}