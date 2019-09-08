/*******************************************************************************************
16. 3Sum Closest
Medium

Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*******************************************************************************************/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        
        int s = 0, diff = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int t = target - nums[i];
            int lft = i+1, rgt = nums.size()-1;
            while(lft < rgt) {
                int n = nums[lft] + nums[rgt];
                if(abs(n-t) < diff ) {diff = abs(n-t); s = n+nums[i];}
                if( n < t) lft++;
                else rgt --;
            }
        }
        return s;
    }
};