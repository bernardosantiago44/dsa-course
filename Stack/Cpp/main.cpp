#include <iostream>
#include "MyQueue.h"

using namespace std;

int main() {
    MyQueue q;

    q.enqueue(1);
    cout << q.peek() << endl;
    q.enqueue(5);
    q.dequeue();
    q.enqueue(9);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}