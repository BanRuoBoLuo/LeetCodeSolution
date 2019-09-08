/*******************************************************************************************
96. Unique Binary Search Trees
Medium

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


*******************************************************************************************/

class Solution {
public:
    int numTrees(int n) {
        vector<int> rst(n+1, 0);
        
        rst[0] = 1;
        for(int k=1; k<=n; k++) {
            for(int r = 1; r<=k; r++){
                rst[k] += rst[r-1]*rst[k-r];
            }
        }
        return rst[n];
    }
};