// https://leetcode.com/problems/palindrome-linked-list/description/
// leetcode: 234

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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* right = reverseList(slow);
        ListNode* left = head;

        // Compare both halves
        while(right != nullptr){
            if(left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }
};

// Insert at end
ListNode* insertNode(ListNode* head, int value){
    ListNode* newNode = new ListNode(value);

    if(head == nullptr)
        return newNode;

    ListNode* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print list
void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = nullptr;

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        head = insertNode(head, x);
    }

    cout << "List: ";
    printList(head);

    LinkedListOperations obj;

    if(obj.isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;

}
