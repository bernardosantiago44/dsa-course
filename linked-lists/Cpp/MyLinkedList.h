#pragma once
#include <stdexcept>
#include <iostream>
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
public:
    MyNodoLL *head,
             *tail;
    int size;

    MyLinkedList();
    ~MyLinkedList();
    int length();
    bool isEmpty();
    int first();
    int last();
    void insertFirst(int data);
    void insertLast(int data);
    void insertAt(int pos, int data);
    void setAt(int pos,int data); //Exc invalid_argument
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    friend ostream& operator<<(ostream& os,const MyLinkedList& ll);

    int getAt(int pos);
};