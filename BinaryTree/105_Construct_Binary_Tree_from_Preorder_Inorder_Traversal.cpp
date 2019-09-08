/*****************************************************************************************
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7


*****************************************************************************************/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        return buildTreeHelper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end()); 
    }
    
    TreeNode* buildTreeHelper(vector<int>::iterator preorder_bgn, vector<int>::iterator preorder_end, vector<int>::iterator inorder_bgn, vector<int>::iterator inorder_end) {
        if(preorder_bgn >= preorder_end || inorder_bgn >= inorder_end) return nullptr;
        
        int val = *preorder_bgn;
        
        auto it = find(inorder_bgn, inorder_end, val);
        if(it == inorder_end) return nullptr;
        
        int leftLen = distance(inorder_bgn, it);        
        
        TreeNode* root = new TreeNode(val);
        root->left = buildTreeHelper(preorder_bgn+1, preorder_bgn+leftLen+1, inorder_bgn, it);
        root->right= buildTreeHelper(preorder_bgn+1+leftLen, preorder_end, it+1, inorder_end);
        return root;
    }
};