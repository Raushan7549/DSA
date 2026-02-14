// https://leetcode.com/problems/reverse-linked-list/description/
// leetcode: 206
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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Insert node at end
ListNode* insertNode(ListNode* head, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == nullptr)
        return newNode;

    ListNode* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }

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

    Solution obj;
    head = obj.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;

}
