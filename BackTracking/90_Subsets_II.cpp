/*******************************************************************************************
90. Subsets II
Medium

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*******************************************************************************************/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> cnts;
        for(int x: nums) cnts[x] ++;
        
        vector<vector<int>> result;
        vector<int> path;
        
        traverse(cnts, cnts.begin(), path, result);
        return result;
    }
    
    void traverse(const map<int, int>& cnts, map<int, int>::iterator it, vector<int>& path, vector<vector<int>>& result){
        if(it == cnts.end()){
            result.push_back(path);
            return;
        }
        
        for(int k = 0; k<=it->second; k++){
            for(int i=0; i<k; i++) path.push_back(it->first);
            traverse(cnts, next(it), path, result);
            for(int i=0; i<k; i++) path.pop_back();
        }
    }
};