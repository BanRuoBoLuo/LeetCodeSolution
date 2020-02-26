/******************************************************************************************
148. Sort List
Medium

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* fast = head, * mid = head;
        ListNode* prev = nullptr;
        
        while(fast != nullptr && fast->next != nullptr) {
            prev = mid;
            fast = fast->next->next;
            mid = mid->next;
        }
        
        prev->next = nullptr;
        
        ListNode* lft = sortList(head);
        ListNode* rgt = sortList(mid);
        
        return merge(lft, rgt);
    }
    
    ListNode* merge(ListNode* lft, ListNode* rgt) {
        ListNode dummy = ListNode(-1);
        ListNode* cur = &dummy;
        
        while(lft != nullptr && rgt != nullptr) {
            if(lft->val < rgt->val) {
                cur->next = lft;
                lft = lft->next;
            } else {
                cur->next = rgt;
                rgt = rgt->next;
            }
            cur = cur->next;
        }
        
        if(lft == nullptr) cur->next = rgt;
        else cur->next = lft;
        
        return dummy.next;
    }  
};