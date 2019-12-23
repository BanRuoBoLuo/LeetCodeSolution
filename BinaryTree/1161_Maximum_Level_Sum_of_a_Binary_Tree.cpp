/*******************************************************************************************
1161. Maximum Level Sum of a Binary Tree
Medium

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

 

Example 1:

Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

 

Note:

    The number of nodes in the given tree is between 1 and 10^4.
    -10^5 <= node.val <= 10^5

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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;
        
        queue<TreeNode*> nds;
        nds.push(root);
        
        int levelSum = INT_MIN;
        int level = 0, rst = 0;
        
        while(!nds.empty()) {
            int N = nds.size();
            int s = 0;
            level ++;
            for(int i=0; i<N; i++) {
                TreeNode* nd = nds.front(); nds.pop();
                if(nd->left != nullptr) nds.push(nd->left);
                if(nd->right !=nullptr) nds.push(nd->right);
                
                s += nd->val;
            }
            if(s > levelSum) {
                levelSum = s;
                rst = level;
            }
        }
        return rst;
    }
};