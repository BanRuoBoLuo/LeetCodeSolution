/******************************************************************************************
872. Leaf-Similar Trees
Easy

Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 ******************************************************************************************/



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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1 = leafSequence(root1);
        vector<int> seq2 = leafSequence(root2);
        
        return std::equal(seq1.begin(), seq1.end(), seq2.begin());
    }
    
    vector<int> leafSequence(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> result;
        
        while(root != nullptr || !nodes.empty()) {
            if(root == nullptr){
                root = nodes.top(); nodes.pop();
                if(root!= nullptr && root->left == nullptr && root->right == nullptr) {
                    result.push_back(root->val);
                }
                root = root->right;
            } else {
                nodes.push(root);
                root = root->left;
            }
        }
        return result;
    }
};