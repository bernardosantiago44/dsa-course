#include <iostream>
#include "MyQueue.h"

using namespace std;

int main() {
    MyQueue q;

    q.enqueue(1);
    cout << q.peek() << endl;

    return 0;
}