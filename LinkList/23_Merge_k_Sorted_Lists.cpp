/*******************************************************************************************
23. Merge k Sorted Lists
Hard

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            if(a == nullptr) return false;
            if(b == nullptr) return true;
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
        for(ListNode* nd: lists) {
            if(nd != nullptr) q.push(nd);
        }
        
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while(!q.empty()) {
            ListNode * nd = q.top(); q.pop();
            if(nd->next != nullptr) q.push(nd->next);
            
            curr->next = nd; curr = nd;
        }
        return dummy.next;
    }
};