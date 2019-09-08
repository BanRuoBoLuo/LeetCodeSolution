/*******************************************************************************************
19. Remove Nth Node From End of List
Medium

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* lst = head;
        for(int i=0; i<n; i++){
            if(lst==nullptr) return nullptr;
            lst = lst->next;
        }
        
        if(lst == nullptr) return head->next;
        
        ListNode* rst = head;
        while(lst->next != nullptr) {
            rst = rst->next;
            lst = lst->next;
        }
        
        rst->next = rst->next->next;
        return head;
    }
};


// 1  2   3   4  5 
// rst   rst     rst

// 1  2  lst