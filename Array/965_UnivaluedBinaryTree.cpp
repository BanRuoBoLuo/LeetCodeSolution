/*******************************************************************************************
965. Univalued Binary Tree
Easy

A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

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
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr) return true;
        
        return TreeValue(root->left, root->val) && TreeValue(root->right, root->val);
        
    }
    
    bool TreeValue(TreeNode* root, int x) {
        if(root == nullptr) return true;
        
        return root->val == x &&  TreeValue(root->left, x) && TreeValue(root->right, x);
    }
};