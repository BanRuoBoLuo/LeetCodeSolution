/*******************************************************************************************
101. Symmetric Tree
Easy

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

 

Note:
Bonus points if you could solve it both recursively and iteratively.

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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        
        return symmetricTree(root->left, root->right);
    }
    
    
    bool symmetricTree(TreeNode* root1, TreeNode* root2) {
        if (root1==nullptr && root2 == nullptr) return true;
        else if (root1 != nullptr && root2 != nullptr) {
            return root1->val == root2->val &&
                symmetricTree(root1->left, root2->right) && 
                symmetricTree(root1->right, root2->left);
        } else {
            return false;
        }
    }
};