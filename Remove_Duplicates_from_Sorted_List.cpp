#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class LinkedListOperations {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;

        if (cur == nullptr)
            return head;

        while (cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;  // free memory
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

// Insert node at end
ListNode* insertNode(ListNode* head, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == nullptr)
        return newNode;

    ListNode* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = nullptr;

    cout << "Enter sorted values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertNode(head, x);
    }

    cout << "Original List: ";
    printList(head);

    LinkedListOperations obj;
    head = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}