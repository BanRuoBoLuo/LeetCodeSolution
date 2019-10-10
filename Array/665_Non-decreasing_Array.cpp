/*******************************************************************************************
665. Non-decreasing Array
Easy

Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:

Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:

Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.

Note: The n belongs to [1, 10,000]. 

*******************************************************************************************/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() <= 2) return true;
        
        int left = 0;
        while(left < nums.size()-1 && nums[left] <= nums[left+1]) left ++;
        if(left == nums.size()-1) return true;
        
        int right = nums.size()-1;
        while(right > 0 && nums[right]  >= nums[right-1]) right --;
        
        return left + 1 == right && (left == 0 || right == nums.size()-1 || nums[right] >= nums[left-1] || nums[right+1] >= nums[left] );
        
    }
};