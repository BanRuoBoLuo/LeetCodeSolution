/******************************************************************************************
283. Move Zeroes
Easy

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

******************************************************************************************/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int idx = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                nums[idx++] = nums[i];
            }
        }
        
        for(; idx < nums.size(); idx++) nums[idx] = 0;
    }
};