*******************************************************************************************/
106. Construct Binary Tree from Inorder and Postorder Traversal
Medium

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7


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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return buildTreeHelper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
    TreeNode* buildTreeHelper(const vector<int>::iterator& inlft, const vector<int>::iterator& inrgt, const vector<int>::iterator& plft, const vector<int>::iterator& prgt) {
        if(inlft>=inrgt || plft>=prgt) return nullptr;
        if(distance(inlft, inrgt) != distance(plft, prgt)) return nullptr;
        
        int val = *(prgt-1);
        auto it = find(inlft, inrgt, val);
        if(it == inrgt) return nullptr;
        
        int len = distance(inlft, it);
        TreeNode* root = new TreeNode(val);
        root->left = buildTreeHelper(inlft, it, plft, plft+len);
        root->right = buildTreeHelper(it+1, inrgt, plft+len, prgt-1);
        return root;
    }
        
};