/*******************************************************************************************
259. 3Sum Smaller
Medium

Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example:

Input: nums = [-2,0,1,3], and target = 2
Output: 2 
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]

Follow up: Could you solve it in O(n2) runtime?

*******************************************************************************************/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int cnt = 0;
        for(int i=0; i< nums.size(); i++) {
            int t = target - nums[i];
            for(int j = i+1, k = nums.size()-1; j < k; ){
                int m = nums[j] + nums[k];
                if(m < t) {cnt += k-j; j++;}
                else k--;
            }
        }
        
        return cnt;
    }
};