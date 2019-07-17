/*******************************************************************************************
82. Remove Duplicates from Sorted List II
Medium

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:

Input: 1->1->1->2->3
Output: 2->3

*******************************************************************************************/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        
        ListNode* result = new ListNode(0);
        ListNode * nd = result;
        ListNode* pivot = head;
        
        while(pivot != nullptr) {
            int cnt = 1;
            ListNode *scan = pivot->next;
            while(scan!=nullptr && scan->val == pivot->val) {cnt++; scan=scan->next;}
            if(cnt == 1) {
                nd->next = pivot;
                nd = nd->next;
            }
            
            pivot = scan;
        }
        
        nd->next = nullptr;
        return result->next;
    }
};