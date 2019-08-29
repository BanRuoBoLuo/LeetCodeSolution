/*******************************************************************************************
414. Third Maximum Number
Easy

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:

Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.

Example 2:

Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:

Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*******************************************************************************************/



class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        long long s = std::numeric_limits<long long>::min();
        long long m = std::numeric_limits<long long>::min();
        long long l = std::numeric_limits<long long>::min();
        
        for(int x: nums) {
            if(x > s && x < m) {
                s = x;
            } else if (x > m && x < l) {
                s = m; m = x;
            } else if (x > l) {
                s = m; m = l; l = x;
            }
        }
        
        return s == std::numeric_limits<long long>::min()? l: s;
    }
};