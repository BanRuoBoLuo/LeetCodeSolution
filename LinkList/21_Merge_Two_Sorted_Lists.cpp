/*******************************************************************************************
21. Merge Two Sorted Lists
Easy

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* result = new ListNode(0);
        ListNode* nd = result;
        while (l1 != nullptr && l2!=nullptr) {
            if(l1->val < l2-> val) {nd->next = l1; l1 = l1->next;}
            else {nd->next = l2; l2 = l2->next;}
            nd = nd->next;
        }
        
        nd->next = l1==nullptr ? l2 : l1;
        return result->next;
    }
};