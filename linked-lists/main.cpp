#include "DoublyNode.h"

int main() {
    DoublyNode head(1);

    // head = DoublyNode::insertAtBeginning(&head, &tail, -10);
    // cout << head.getNext()->toString() << endl;
    DoublyNode current = DoublyNode::insertAtBeginning(&head, &head, -5);
    cout << current.toString() << endl;
    cout << current.getNext()->toString() << endl;
    /*
    // Traverse the list
    SinglyNode* current = &head;
    if (current != nullptr) {
        cout << current->toString();
        current = current->getNext();
    }

    while (current != nullptr) {
        cout << " <-> " << current->toString();
        current = current->getNext();
    }
    cout << endl;

    cout << SinglyNode::search(&head, 15) << endl;

    */
    
    return 0;
}