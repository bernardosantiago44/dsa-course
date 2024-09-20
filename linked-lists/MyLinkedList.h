#pragma once
#include <stdexcept>
using namespace std;

struct MyNodoLL {
    int data;
    MyNodoLL *next;

    MyNodoLL(int data, MyNodoLL* next) {
        this->data = data;
        this->next = next;
    }

    MyNodoLL(int data) : MyNodoLL(data, nullptr) {}
};

class MyLinkedList {
private:
    MyNodoLL *head,
             *tail;
    int size;

public:
    MyLinkedList();
    ~MyLinkedList();
    int length();
    bool isEmpty();
    int first();
    int last();
    void insertFirst(int data);

    int getAt(int pos);
};