#pragma once
#include <iostream>

using namespace std;

class SinglyNode {
private:
    int value;
    SinglyNode* next; // Pointer to next node, nil if last node

public:
    SinglyNode();
    SinglyNode(int value);
    SinglyNode(int value, SinglyNode* next);

    string toString();
    SinglyNode* getNext();
    void setNext(SinglyNode* next);
    static bool search(SinglyNode* head, int value);
};