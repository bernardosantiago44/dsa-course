#include "MyHeap.h"

int main() {
    int valores[10] = {0, -15, 21, 12, 24, 9, 11, 32, 16};
    MyHeap q(valores, 9);
    q.imprimir();

    while(!q.isEmpty()) {
        cout << q.top() << ", ";
        q.pop();
    }
    cout << endl;

    return 0;
}