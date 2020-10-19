/*******************************************************************************************
209. Minimum Size Subarray Sum
Medium

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

*******************************************************************************************/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int len = INT_MAX;
        int bgn = 0;
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            
            if(sum >= s) {
                while(sum >= s) {
                    sum -= nums[bgn];
                    bgn ++;
                }
                
                len = min(len, i-bgn+2);
            }
        }
        
        return len == INT_MAX? 0: len;
    }
};