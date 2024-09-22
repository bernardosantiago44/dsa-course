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
    this->size++;

    if (size == 1) {
        tail = head;
    }
}

MyLinkedList::~MyLinkedList() {
    while (head != nullptr) {
        MyNodoLL* current = head->next;
        delete current;
        head = current;
    }
}