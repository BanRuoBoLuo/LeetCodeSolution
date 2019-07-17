/*******************************************************************************************
78. Subsets
Medium

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*******************************************************************************************/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        result.push_back(vector<int> {});
        for(int i=0; i<nums.size(); i++) {
            int N = result.size();
            for(int k=0; k<N; k++){
                vector<int> rst(result[k].begin(), result[k].end());
                rst.push_back(nums[i]);
                result.push_back(rst);
            }
        }
        
        return result;
    }
};