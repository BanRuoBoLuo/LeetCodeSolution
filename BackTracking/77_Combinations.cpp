/*******************************************************************************************
77. Combinations
Medium

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*******************************************************************************************/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        
        dfs(n, k, path, result);
        return result;
    }
    
    void dfs(int n, int k, vector<int>& path, vector<vector<int>>& result) {
        if(k == 0) {
            result.push_back(path);
            return;
        } 
        
        if(k > n) return;
        
        path.push_back(n);
        dfs(n-1, k-1, path, result);
        path.pop_back();
        
        dfs(n-1, k, path, result);
    }
};