/******************************************************************************************
203. Remove Linked List Elements
Easy

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5


******************************************************************************************/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dum = new ListNode(0);
        
        ListNode* nd = dum;
        while(head!=nullptr){
            if(head->val != val) {
                nd->next = head;
                nd = nd->next;
            }
            head = head->next;
        }
        nd->next = nullptr;/*truncate trailing nodes*/
        return dum->next;
    }
};