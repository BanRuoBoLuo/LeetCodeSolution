/*******************************************************************************************
257. Binary Tree Paths
Easy

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> path;
        traverse(root, path, result);
        
         vector<string> rst;
        string connector = "->";
        for(const auto& p: result) {
            rst.push_back(join(p, connector));
        }
        return rst;
    }
    
    void traverse(TreeNode* root, vector<int>& path, vector<vector<int>>& result){
        if(root==nullptr) {
            return;
        }
        
        if(root->left == nullptr && root->right == nullptr) {
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        path.push_back(root->val);
        traverse(root->left, path, result);
        traverse(root->right, path, result);
        
        path.pop_back();
    }
    
    string join(const vector<int>& path, const string& connector){
        if(path.empty()) return "";
        
        string rst = to_string(path[0]);
        for(auto it = path.begin()+1; it!=path.end(); ++it){
            rst += connector + to_string(*it);
        }
        return rst;
    }
};