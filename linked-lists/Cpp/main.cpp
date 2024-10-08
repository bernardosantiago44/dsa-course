#include <iostream>
#include "MyLinkedList.h"

int main() {
    try {
        {
        MyLinkedList lista;
        lista.insertFirst(5);
        lista.insertFirst(1);
        lista.insertFirst(-4);

        lista.insertLast(9);
        lista.insertLast(15);
        lista.insertLast(21);

        lista.insertAt(2, 3);
        lista.insertAt(0, -7);
        lista.insertAt(7, 26);
        cout << lista << endl;
        lista.removeLast();
        cout << lista << endl;
        lista.insertLast(5);
        cout << lista << endl;
        lista.removeAt(2);
        cout << lista << endl;
        }
    } catch (invalid_argument e) {
        cout << "El programa terminó de manera inesperada: " << e.what() << endl;
    }
    return 0;
}