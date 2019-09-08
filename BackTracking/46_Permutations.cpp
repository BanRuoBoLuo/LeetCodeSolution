/*******************************************************************************************
46. Permutations
Medium

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*******************************************************************************************/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        traverse(nums, 0, result);
        return result;
    }
    
    
    void traverse(vector<int>& nums, int pos, vector<vector<int>> &result){
        if(pos==nums.size()){
            result.push_back(nums);
            return;
        }
        
        for(int i=pos; i<nums.size(); i++){
            swap(nums[i], nums[pos]);
            traverse(nums, pos+1, result);
            swap(nums[i], nums[pos]);
        }
    }
};