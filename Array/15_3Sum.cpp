/*******************************************************************************************
15. 3Sum
Medium

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*******************************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        // if(nums.size() < 3) return vector<vevtor<int>>{};
        
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()){
            if(nums[i] > 0) return result;
            
            int target = -nums[i];
            int j = i+1, k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k] < target) j++;
                else if (nums[j]+nums[k] > target) k--;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                }
            }
            
            i++;
            while(i<nums.size() && nums[i] == nums[i-1]) i++;
        }
        
        return result;
    }
};