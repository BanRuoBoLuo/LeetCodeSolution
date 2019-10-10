/*******************************************************************************************
216. Combination Sum III
Medium

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

    All numbers will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]


*******************************************************************************************/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> path;
        vector<vector<int>> result;
        
        traverse(1, n, k, path, result);
        return result;
    }
    
    void traverse(int pos, int n, int k, vector<int>& path, vector<vector<int>>& result) {
        if(k == 0 && n == 0) {
            result.push_back(path);
            return;
        }
        
        if(pos > 9 || n < 0 || k < 0) return;
        
        traverse(pos+1, n, k, path, result);
        
        path.push_back(pos);
        traverse(pos+1, n-pos, k-1, path, result);
        path.pop_back();
    }
};