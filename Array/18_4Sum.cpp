/*******************************************************************************************
18. 4Sum
Medium

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*******************************************************************************************/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        int i=0;
        while(i<nums.size()-3){
            int j = i+1;
            while(j<nums.size()-2) {
                int t = target-nums[i]-nums[j];
                int lft = j+1, rgt = nums.size()-1;
                while(lft<rgt){
                    if(nums[lft]+nums[rgt] < t) lft++;
                    else if(nums[lft]+nums[rgt] > t) rgt--;
                    else {
                        result.push_back(vector<int> {nums[i], nums[j], nums[lft], nums[rgt]});
                        lft++; rgt--;
                        while(lft < rgt && nums[lft] == nums[lft-1]) lft++;
                    }
                }
                j++;
                while(j<nums.size()-2 && nums[j] == nums[j-1]) j++;   
            }
            i++;
            while(i<nums.size()-3 && nums[i] == nums[i-1]) i++;   
        }
        return result;
    }
};