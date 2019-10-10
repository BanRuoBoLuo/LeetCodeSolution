/*******************************************************************************************
145. Binary Tree Postorder Traversal
Hard

Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

Follow up: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> result;
        stack<TreeNode*> nodes;
        
        TreeNode* lastVisited = nullptr;
        while(root!=nullptr || !nodes.empty()) {
            if(root==nullptr){
                TreeNode* nd = nodes.top(); 
                if(nd->right != nullptr && lastVisited != nd->right) {
                    root=nd->right;
                } else {
                    result.push_back(nd->val); nodes.pop();
                    lastVisited = nd;
                    root = nullptr;
                }
            } else {
                nodes.push(root);
                root = root->left;
            }
        }
        return result;
    }
};