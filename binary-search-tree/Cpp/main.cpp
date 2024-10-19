#include "MyBST.h"
#include <iostream>

using namespace std;

int main() {
    MyBST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(90);
    tree.insert(15);
    tree.insert(70);
    tree.insert(68);
    tree.insert(35);
    tree.insert(80);
    tree.insert(40);
    tree.insert(33);
    tree.insert(61);
    tree.insert(5);
    tree.insert(69);
    tree.insert(75);
    tree.insert(90);

    tree.visit(1);
    tree.visit(2);
    tree.visit(3);
    tree.visit(4);

    cout << tree.height() << endl;
    tree.ancestors(33);

    return 0;
}