/*******************************************************************************************
543. Diameter of Binary Tree
Easy

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them. 


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
    
    struct Result{
        int height;
        int diameter;
        
        Result() :height(0), diameter(0) {}
        Result(int a, int b) :height(a), diameter(b) {}
    };
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        Result r = diameter(root);
        
        return r.diameter;
    }
    
    Result diameter(TreeNode* root) {
        if(root == nullptr) return Result(0, 0);
        
        Result lft = diameter(root->left);
        Result rgt = diameter(root->right);
        
        int dia = max(lft.diameter, rgt.diameter);
        dia = max(dia, lft.height + rgt.height);
        return Result(max(lft.height, rgt.height) + 1, dia);
    }
     
};