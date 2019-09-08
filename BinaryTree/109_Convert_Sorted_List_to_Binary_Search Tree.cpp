/*******************************************************************************************
109. Convert Sorted List to Binary Search Tree
Medium

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5


*******************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* mid = head, *lst = head;
        
        while(lst != nullptr && lst->next != nullptr) {
            lst = lst->next->next;
            prev = mid;
            mid = mid->next;
        }
        
        TreeNode* root = new TreeNode(mid->val);
        if(prev != nullptr) {
            prev->next = nullptr;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(mid->next);
        return root;
        
    }
};