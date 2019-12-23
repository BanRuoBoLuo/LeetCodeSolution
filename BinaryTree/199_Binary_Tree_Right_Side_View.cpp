/*************************************************************************
199. Binary Tree Right Side View
Medium

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rst;
        
        if(root==nullptr) return rst;
        
        queue<TreeNode*> levels;
        levels.push(root);
        
        while(!levels.empty()){
            rst.push_back(levels.front()->val);
            
            int N = levels.size();
            for(int i=0; i<N; i++){
                TreeNode* nd = levels.front(); levels.pop();
                if(nd->right != nullptr) levels.push(nd->right);
                if(nd->left != nullptr) levels.push(nd->left);
            }
        }
        
        return rst;
    }
};