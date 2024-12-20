// wap in cpp in which we in which we have 2 lists in first case we have both the lists empty and in 2nd case one list we be empty and one will be having 0 
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;

    cout << "Case 1: Both lists are empty" << endl;
    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    l1 = nullptr;
    l2 = new ListNode(0);

    cout << "\nCase 2: One list is empty, the other has one element (0)" << endl;
    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    return 0;
}
