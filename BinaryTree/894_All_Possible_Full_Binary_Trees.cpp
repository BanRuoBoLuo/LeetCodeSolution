/*******************************************************************************************
894. All Possible Full Binary Trees
Medium

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.

 

Example 1:

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Explanation:

 

Note:

    1 <= N <= 20
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
    vector<TreeNode*> allPossibleFBT(int N) {
        
        vector<vector<TreeNode*>> rst(N+1);
        
        TreeNode* nd = new TreeNode(0);
        rst[1].push_back(nd);
        /*
        rst[k] = rst[i] * rst[k-i-1] for i = 1...k-2
        */
        for(int i=3; i<=N; i++) {
            for(int left = 1; left <= i-2; left++){
                for(auto lft: rst[left]){
                    for(auto rgt: rst[i-1-left]){
                        TreeNode * nd = new TreeNode(0);
                        nd->left = lft; nd->right = rgt;
                        rst[i].push_back(nd);
                    }
                }
            }
        }
        return rst[N];
        
    }
};