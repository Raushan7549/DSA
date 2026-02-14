// https://leetcode.com/problems/middle-of-the-linked-list/description/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertNode(head, x);
    }

    cout << "Original List: ";
    printList(head);

    LinkedListOperations obj;
    ListNode* mid = obj.middleNode(head);

    if (mid != nullptr)
        cout << "Middle Node Value: " << mid->val << endl;

    return 0;

}
