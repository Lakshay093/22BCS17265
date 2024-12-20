// we have 2 given linkedlists l1 = 1,3,4 and l2 = 1,2,5 and the output as the combination of the 1,1,2,3,4,5 using appending of both the list
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* append(ListNode* head, int val) {
    if (head == nullptr) {
        return new ListNode(val);
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = nullptr;
    l1 = append(l1, 1);
    l1 = append(l1, 3);
    l1 = append(l1, 4);

    ListNode* l2 = nullptr;
    l2 = append(l2, 1);
    l2 = append(l2, 2);
    l2 = append(l2, 5);

    ListNode* mergedList = mergeLists(l1, l2);

    cout << "Merged Linked List: ";
    printList(mergedList);

    return 0;
}
