// Bernardo Santiago Marín
// A01638915

#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

struct MyNodoLL {
    int value;
    string key;
    MyNodoLL *next;

    MyNodoLL(string key, int value, MyNodoLL* next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }

    MyNodoLL(string key, int value) : MyNodoLL(key, value, nullptr) {}
};

class MyLinkedList {
public:
    MyNodoLL *head,
             *tail;
    int size;

    MyLinkedList();
    ~MyLinkedList();
    int length();
    bool isEmpty();
    void insertFirst(string key, int value);
    int getAt(string key);
    void removeFirst();
    void removeLast();
    bool removeAt(string key); // Regresa si la eliminación fue exitosa
    friend ostream& operator<<(ostream& os,const MyLinkedList& ll) {
        MyNodoLL* current = ll.head;
        for (int i = 0; i < ll.size; i++) {
            os << "[" << current->key << ", " << current->value << "], ";
            current = current->next;
        }
        return os;
    }

};