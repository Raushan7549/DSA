// https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    // Reverse from start to end (inclusive)
    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* prev = end->next;
        ListNode* curr = start;

        while (prev != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next ;
        }

        return end;  // new head after reversal
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* curr = head;
        ListNode* start = head;
        ListNode* prevTail = nullptr;
        ListNode* finalHead = nullptr;

        int count = 0;

        while (curr) {
            count++;

            if (count % k == 0) {
                ListNode* end = curr;
                ListNode* nextGroup = curr->next;

                // reverse current k group
                ListNode* newHead = reverseList(start, end);

                if (!finalHead)
                    finalHead = newHead;

                if (prevTail)
                    prevTail->next = newHead;

                prevTail = start;
                start = nextGroup;
                curr = nextGroup;
            } else {
                curr = curr->next;
            }
        }

        if (prevTail)
            prevTail->next = start;

        return finalHead;
    }
};

