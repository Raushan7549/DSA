// https://leetcode.com/problems/swap-nodes-in-pairs/
// leetcode: 24;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while(curr!=nullptr && curr->next!=nullptr){
            next = curr->next->next;
            prev->next = curr->next;
            prev->next->next = curr;
            curr->next = next;
            prev = curr;
            curr = next;
        }
        return dummy->next;
    }
};
