// LEETCODE q_no.: 328
// https://leetcode.com/problems/odd-even-linked-list/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* odd = head;
        ListNode* oddhead = head;
        ListNode* even = head->next; 
        ListNode* evenhead = head->next; 
        head = head->next->next;
        while(head!=nullptr){
            odd->next = head;
            even->next = head->next;
            odd = odd->next;
            even = even->next;
            head = head->next ? head->next->next : nullptr;
        }
        odd->next = evenhead;
        return oddhead;
    }

};
