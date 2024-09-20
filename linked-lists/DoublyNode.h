#pragma once
#include "SinglyNode.h"

class DoublyNode : public SinglyNode {
private:
    SinglyNode* previous;
public:
    DoublyNode(int val, SinglyNode* previous = nullptr, SinglyNode* next = nullptr);
    SinglyNode* getPrevious();
    void setPrevious(SinglyNode* prev);

    static DoublyNode insertAtBeginning(DoublyNode* head, DoublyNode* tail, int val);
};