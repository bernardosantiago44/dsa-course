#include "MyHeap.h"

int main() {
    MyHeap q;
    q.push(3);
    q.push(4);
    q.imprimir();
    q.push(5);
    q.push(6);
    q.imprimir();
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(20);
    q.imprimir();

    return 0;
}