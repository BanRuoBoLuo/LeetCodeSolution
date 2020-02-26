/*******************************************************************************************
300. Longest Increasing Subsequence
Medium

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

Note:

    There may be more than one LIS combination, it is only necessary for you to return the length.
    Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*******************************************************************************************/

class Solution {
public:
    int lengthOfLIS2(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        vector<int> dp(nums.size(), 1);
        
        for(int k=1; k<nums.size(); k++) {
            for(int i=0; i<k; i++) {
                if(nums[i] < nums[k]) dp[k] = max(dp[k], dp[i]+1);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    
     int lengthOfLIS(vector<int>& nums) {
         vector<int> inc;
         for(int x: nums) {
             auto it = lower_bound(inc.begin(), inc.end(), x);
             if(it == inc.end()) inc.push_back(x);
             else *it = x;
         }
         return inc.size();
     }
};