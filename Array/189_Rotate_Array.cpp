/*******************************************************************************************
189. Rotate Array
Easy

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*******************************************************************************************/


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return;
        
        int N = nums.size();
        k = k % N;
        
        if(k == 0) return;
        vector<int> tmp(nums.begin()+N-k, nums.end());
        for(int i=N-1; i>=k; i--) {
            nums[i] = nums[i-k];
        }
        for(int i=k-1; i>=0; i--){
            nums[i] = tmp[i];
        }
    }
};