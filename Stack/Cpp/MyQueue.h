#pragma Once
#include "../../linked-lists/Cpp/MyLinkedList.h"

class MyQueue {
    private:
        MyLinkedList lista;
    public:
        MyQueue();
        ~MyQueue();

        void enqueue(int data);
        void dequeue();
        void flush();
        
        int  peek();
        int  length();
        bool isEmpty();
};