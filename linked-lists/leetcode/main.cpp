struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr && list2 == nullptr) {
        return nullptr;
    }

    ListNode* head1 = list1;
    ListNode* head2 = list2;
    ListNode* newHead = new ListNode();
    ListNode* current = newHead;

    // Merge the lists accordingly
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val >= head2->val) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    while (head1 != nullptr) {
        current->next = head1;
        head1 = head1->next;
        current = current->next;
    }

    while (head2 != nullptr) {
        current->next = head2;
        head2 = head2->next;
        current = current->next;

    }
    return newHead->next;
}

int main() {
    ListNode* one1 = new ListNode(1);
    ListNode* one2 = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);

    one1->next = two;
    two->next = four;
    one2->next = three;
    three->next = four;

    mergeTwoLists(one1, one2);

    return 0;
}