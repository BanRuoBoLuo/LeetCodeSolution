/*******************************************************************************************
637. Average of Levels in Binary Tree
Easy
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:

Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

Note:

    The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        
        if(root==nullptr) return result;
        queue<TreeNode*> level;
        level.push(root);
        
        while(!level.empty()){
            int N = level.size();
            double total = 0.0;
            TreeNode* nd;
            for(int i=0; i<N; i++){
                nd = level.front(); level.pop();
                total += nd->val;
                if(nd->left != nullptr) level.push(nd->left);
                if(nd->right !=nullptr) level.push(nd->right);
            }
            result.push_back(total/N);
        }
        return result;
    }
};