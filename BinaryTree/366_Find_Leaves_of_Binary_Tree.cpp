/*******************************************************************************************
366. Find Leaves of Binary Tree
Medium

Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

 

Example:

Input: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    

Output: [[4,5,3],[2],[1]]

 

Explanation:

1. Removing the leaves [4,5,3] would result in this tree:

          1
         / 
        2          

 

2. Now removing the leaf [2] would result in this tree:

          1          

 

3. Now removing the leaf [1] would result in the empty tree:

          []         

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        if(root == nullptr) return {};
        
        vector<vector<int>> rst;
        vector<vector<int>> lft = findLeaves(root->left);
        vector<vector<int>> rgt = findLeaves(root->right);
        
        int i=0;
        for(; i<lft.size() && i<rgt.size(); i++) {
            lft[i].insert(lft[i].end(), rgt[i].begin(), rgt[i].end());
            rst.push_back(lft[i]);
        }
        while(i<lft.size()){
            rst.push_back(lft[i]);
            i++;
        }
        while(i<rgt.size()){
            rst.push_back(rgt[i]);
            i++;
        }
        rst.push_back(vector<int> {root->val});
        return rst;
    }
};