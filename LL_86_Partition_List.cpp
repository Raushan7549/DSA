// https://leetcode.com/problems/partition-list/description/
// 86. Partition List
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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !(head->next) ) return head;

        ListNode* dummy1 = new ListNode(0);
        ListNode* prev1 = dummy1; 

        ListNode* dummy2 = new ListNode(0);
        ListNode* prev2 = dummy2; 

        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = nullptr;
            if(curr->val < x){
                prev1->next = curr;
                prev1 = prev1->next;
            } else{
                prev2->next =curr;
                prev2 = prev2->next;
            }
                curr = next;
        }
        prev1->next = dummy2->next;

        return dummy1->next;
    }
};
