/*******************************************************************************************
124. Binary Tree Maximum Path Sum
Hard

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        int r = rootNodeSum(root, sum);
        
        return sum;
    }
    
    int rootNodeSum(TreeNode* root, int& sum) {
        if(root == nullptr) return 0;
        
        int lft = rootNodeSum(root->left, sum);
        int rgt = rootNodeSum(root->right, sum);
        
        int rst = root->val;
        if(lft > 0) rst += lft;
        if(rgt > 0) rst += rgt;
        sum = max(sum, rst);
        
        return max(lft, rgt) > 0? max(lft, rgt) + root->val: root->val;
    }
};