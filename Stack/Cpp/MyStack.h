#pragma Once
#include "../../linked-lists/Cpp/MyLinkedList.h"

class MyStack {
    private:
        MyLinkedList lista;

    public:
        void push(int data);
        void pop();
        int top();
        bool isEmpty();
        int length();
        void flush();
};