/*************************************************************************
86. Partition List
Medium

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5


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
    ListNode* partition(ListNode* head, int x) {
        ListNode* rst = new ListNode(0);
        rst->next = head;
        
        ListNode *nd = rst;
        ListNode *prev = rst, *curr = head;
        
        while( curr != nullptr) {
            if(curr->val < x) {
                if(curr == nd->next) {
                    nd = nd->next;
                    prev = curr;
                    curr = curr->next;
                } else {
                    ListNode * tmp = curr->next;
                    
                    curr->next = nd->next;
                    nd->next = curr;
                    nd = curr;
                
                    prev->next = tmp;
                    curr = tmp;
                }
            } else {
                prev= curr;
                curr = curr->next;
            }
        }
        return rst->next;
    }
};