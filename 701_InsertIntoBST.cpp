/******************************************************************************************
701. Insert into a Binary Search Tree
Medium

Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

*******************************************************************************************/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root) return new TreeNode(val);
        
        TreeNode* prev = nullptr;
        TreeNode* nd = root;
        
        while(nd) {
            prev = nd;
            if(nd->val < val) nd = nd->right;
            else if (nd->val > val) nd = nd->left;
            else return nullptr;
        }
        
        if(prev->val < val) prev->right = new TreeNode(val);
        else prev->left = new TreeNode(val);
        
        return root;
        
    }
};