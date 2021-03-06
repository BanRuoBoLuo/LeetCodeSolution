/*******************************************************************************************

532. K-diff Pairs in an Array
Easy

Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Example 1:

Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:

Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:

Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).

Note:

    The pairs (i, j) and (j, i) count as the same pair.
    The length of the array won't exceed 10,000.
    All the integers in the given input belong to the range: [-1e7, 1e7].

*******************************************************************************************/



class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int rst = 0, idx=0;
        while(idx < nums.size()) {
            auto it = lower_bound(nums.begin()+idx+1, nums.end(), nums[idx]+k);
            if(it != nums.end() && *it == nums[idx]+k) rst++;
         
            idx ++;
            while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        }
        return rst;
    }

        int findPairs2(vector<int>& nums, int k) {
        if(k < 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int lft = 0, rgt = 1;
        int cnt = 0;
        while(rgt < nums.size()) {
            int d = nums[rgt] - nums[lft];
            if (d < k) rgt ++;
            else if ( d > k) lft ++;
            else {
                if(lft != rgt)cnt ++;
                lft ++; 
                while(lft < nums.size() && nums[lft] == nums[lft-1]) lft ++;
                rgt = lft + 1;
            }
        }
        return cnt;
    }
};