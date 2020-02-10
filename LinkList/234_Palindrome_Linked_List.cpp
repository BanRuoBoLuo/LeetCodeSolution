/******************************************************************************************

234. Palindrome Linked List
Easy

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        } 
        slow = reverse(slow);
        ListNode *rt = slow;

        while(rt != nullptr && head != slow) {
            if(rt->val != head->val) return false;
            
            rt = rt->next;
            head = head->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        ListNode* nt = head->next;
        ListNode* rt = reverse(head->next);
        if(rt == nullptr) return head;
        
        nt->next = head;
        head->next = nullptr;
        return rt;
    }
};