/******************************************************************************************
1214. Two Sum BSTs
Medium

Given two binary search trees, return True if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

 

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.

Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false

 

Constraints:

    Each tree has at most 5000 nodes.
    -10^9 <= target, node.val <= 10^9

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1 == nullptr || root2 == nullptr) return false;
        
        if(root1->val < target - root2->val ) {
            return twoSumBSTs(root1->right, root2, target) || 
                twoSumBSTs(root1, root2->right, target);
        } else if (root1->val > target - root2->val) {
            return twoSumBSTs(root1->left, root2, target) || 
                twoSumBSTs(root1, root2->left, target);
        } else return true;
    }
};