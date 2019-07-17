/*******************************************************************************************
83. Remove Duplicates from Sorted List
Easy

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2

Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

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
        
        ListNode* pivot = head;
        for(ListNode* nd = head->next; nd != nullptr; nd=nd->next) {
            if(nd->val != pivot->val){
                pivot->next = nd;
                pivot = pivot->next;
            }
        }
        
        pivot->next = nullptr;
        return head;
    }
};