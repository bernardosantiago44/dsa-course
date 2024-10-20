#include "PriorityQueue.h"

int main() {
    PriorityQueue<int> q(2);
    q.push(3);
    q.push(4);
    q.print();
    q.push(5);
    q.push(6);
    q.print();
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(20);
    q.print();

    return 0;
}