/*******************************************************************************************
39. Combination Sum
Medium

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

*******************************************************************************************/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> result;
        
        traverse(candidates, 0, target, path, result);
        return result;
    }
    
    void traverse(const vector<int>& candidates, int pos, int target, vector<int>& path, vector<vector<int>>& result) {
        if(target == 0) {
            result.push_back(path);
            return;
        }
        
        if(pos >= candidates.size()) return;
                
        for(int i=0; target-candidates[pos]*i >= 0; i++){
            for(int j=0; j<i; j++) path.push_back(candidates[pos]);
            traverse(candidates, pos+1, target-i*candidates[pos], path, result);
            for(int j=0; j<i; j++) path.pop_back();
        }
        
    }
};