/*******************************************************************************************
94. Binary Tree Inorder Traversal
Medium

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> nodes;
        vector<int> result;
        while(!nodes.empty() || root != nullptr) {
            if(root == nullptr) {
                root = nodes.top(); nodes.pop();
                result.push_back(root->val);
                root = root->right;
            } else {
                nodes.push(root);
                root = root->left;
            }
        }
        return result;
    }
};