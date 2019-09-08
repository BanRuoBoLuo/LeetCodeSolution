/*************************************************************************
102. Binary Tree Level Order Traversal
Medium

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]


*************************************************************************/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()) {
            int N = level.size();
            vector<int> L;
            for(int i=0; i<N; i++){
                TreeNode* nd = level.front(); level.pop();
                L.push_back(nd->val);
                
                if(nd->left != nullptr) level.push(nd->left);
                if(nd->right != nullptr)level.push(nd->right);
            }
            result.push_back(L);
        }
        return result;
    }
};