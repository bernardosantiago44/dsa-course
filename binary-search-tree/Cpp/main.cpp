#include "MyBST.h"
#include <iostream>

using namespace std;

int main() {
    MyBST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(10);
    tree.insert(15);
    tree.insert(8);
    tree.insert(70);
    tree.insert(68);
    tree.insert(35);
    tree.insert(100);
    tree.insert(65);
    tree.insert(69);
    tree.insert(74);
    tree.insert(105);

    tree.inorder();
    cout << tree.remove(68) << endl;
    cout << tree.remove(15) << endl;
    tree.inorder();


    return 0;
}