#include "MyQueue.h"

MyQueue::MyQueue() {

}

MyQueue::~MyQueue() {

}

bool MyQueue::isEmpty() {
    return this->lista.isEmpty();
}

int MyQueue::length() {
    return this->lista.length();
}

void MyQueue::enqueue(int data) {
    this->lista.insertLast(data);
}

void MyQueue::dequeue() {
    this->lista.removeFirst();
}

int MyQueue::peek() {
    return this->lista.last();
}