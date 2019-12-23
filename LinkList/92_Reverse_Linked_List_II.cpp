/*************************************************************************
92. Reverse Linked List II
Medium

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL


*************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode* rst = new ListNode(0);
        rst->next = head;
        
        ListNode* curr = rst;
        ListNode* prev = nullptr;
        for(int i=0; i<m; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* reverseTail = curr, *reverseStart = prev;
        for (int i = m; i <= n; i++){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        reverseStart->next = prev;
        reverseTail->next = curr;
        
        return rst->next;
        
    }
};