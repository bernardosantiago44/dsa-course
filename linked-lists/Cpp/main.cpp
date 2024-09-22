#include <iostream>
#include "MyLinkedList.h"

int main() {
    try {
        MyLinkedList lista;
        lista.insertFirst(5);
        lista.insertFirst(1);
        lista.insertFirst(-4);
        cout << lista.first() << endl;
        cout << lista.last() << endl;
    } catch (invalid_argument e) {
        cout << "El programa terminó de manera inesperada: " << e.what() << endl;
    }
    return 0;
}