/******************************************************************************************
40. Combination Sum II
Medium

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]



note:
    consider duplications
******************************************************************************************/


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> result;
        
        traverse(candidates, target, 0, path, result);
        return result;
    }
    
    void traverse(vector<int>& candidates, int target, int pos, vector<int>& path, vector<vector<int>>& result) {
        if(target == 0){
            result.push_back(path);
            return;
        }
        
        if(pos >= candidates.size()) return;
        
        int idx = pos+1;
        while(idx < candidates.size() && candidates[idx] == candidates[pos]) idx ++;
        
        for(int i=0; i<=idx-pos && target-candidates[pos]*i >= 0; i++) {
            for(int j=0; j<i; j++) path.push_back(candidates[pos]);
            traverse(candidates, target-candidates[pos]*i, idx, path, result);
            for(int j=0; j<i; j++) path.pop_back();
        }
    }
};