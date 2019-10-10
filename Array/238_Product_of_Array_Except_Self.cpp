/*******************************************************************************************
238. Product of Array Except Self
Medium

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)


*******************************************************************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        size_t N = nums.size();
        vector<int> result(N, 1);
        
        for(int i=1; i<N; i++){
            result[i] = result[i-1]*nums[i-1];
        }
        
        int rgt = 1;
        for(int i=N-1; i>=0; i--){
            result[i] *= rgt;
            rgt *= nums[i];
        }
        
        return result;   
    }
};