/*************************************************************************
1022. Sum of Root To Leaf Binary Numbers
Easy

Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 
Example 1:

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
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
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeaf(root, 0);
    }
    
    int sumRootToLeaf(TreeNode* root, int parent){
        if(root==nullptr) return 0;
        
        if(root->left == nullptr && root->right == nullptr) 
            return parent * 2 + root->val;
        
        return sumRootToLeaf(root->left, parent*2+root->val) + sumRootToLeaf(root->right, parent*2+root->val);
    }
};