/******************************************************************************************
53. Maximum Subarray
Easy

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

******************************************************************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum=0, maxSum = INT_MIN;
        for(auto x : nums) {
            sum += x;
            maxSum = max(maxSum, sum);

            if(sum < 0) sum = 0;
        }
        
        return maxSum;
    }
};