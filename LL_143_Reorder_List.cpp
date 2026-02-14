// 143. Reorder List
// https://leetcode.com/problems/reorder-list/description/

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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr!=nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        }
        return prev;
    }
    void reorderList(ListNode* head){
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=nullptr && fast->next !=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newhead = reverse(slow->next);

        slow->next = nullptr;

        slow = head;

        while(slow!=nullptr && newhead!=nullptr){
            ListNode* slowNext = slow->next;
            ListNode* newheadNext = newhead->next;
            newhead->next=slowNext;
            slow->next = newhead;
            slow = slowNext;
            newhead = newheadNext;
        }
    }
};
