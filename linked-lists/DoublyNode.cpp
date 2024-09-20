#include "DoublyNode.h"

DoublyNode::DoublyNode(int val, SinglyNode* previous, SinglyNode* next) : SinglyNode(val, next) {
    this->previous = previous;
}

void DoublyNode::setPrevious(SinglyNode* prev) {
    this->previous = prev;
}

SinglyNode* DoublyNode::getPrevious() {
    return this->previous;
}

DoublyNode DoublyNode::insertAtBeginning(DoublyNode* head, DoublyNode* tail, int val) {
    DoublyNode node(val, nullptr, head);
    // head->setPrevious(&node);
    return node;
}