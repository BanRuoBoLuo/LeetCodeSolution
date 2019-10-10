/******************************************************************************************
144. Binary Tree Preorder Traversal
Medium

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?


******************************************************************************************/

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> result;
        
        while(root!=nullptr || !nodes.empty()){
            if(root==nullptr){
                root = nodes.top(); nodes.pop();
            } else {
                result.push_back(root->val);
                nodes.push(root->right);
                root = root->left;
            }
        }
        return result;
    }
};