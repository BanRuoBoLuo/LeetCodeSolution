/*******************************************************************************************
113. Path Sum II
Medium

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]


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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> result;
        
        traverse(root, sum, path, result);
        return result;
    }
    
    void traverse(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& result) {
        if(root == nullptr) return;
        
        path.push_back(root->val);
        int target = sum - root->val;
        
        if(root->left==nullptr && root->right==nullptr && target == 0){
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        traverse(root->left, target, path, result);
        traverse(root->right, target, path, result);
        
        path.pop_back();
    }
};