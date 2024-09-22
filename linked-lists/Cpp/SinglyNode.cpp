#include "SinglyNode.h"

// Constructors
SinglyNode::SinglyNode(int value, SinglyNode* next) {
    this->value = value;
    this->next = next;
}
SinglyNode::SinglyNode(int value) : SinglyNode(value, nullptr) {}
SinglyNode::SinglyNode() : SinglyNode(0) {}

string SinglyNode::toString() {
    return to_string(value);
}

void SinglyNode::setNext(SinglyNode* next) {
    this->next = next;
}

SinglyNode* SinglyNode::getNext() {
    return next;
}

bool SinglyNode::search(SinglyNode* head, int value) {
    SinglyNode* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}