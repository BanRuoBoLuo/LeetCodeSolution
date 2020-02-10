/*******************************************************************************************
164. Maximum Gap
Hard

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.

Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

Note:

    You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    Try to solve it in linear time/space.

*******************************************************************************************/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // bucket sort
        if(nums.empty()) return 0;
        
        int N = nums.size();
        int lft = *min_element(nums.begin(), nums.end());
        int rgt = *max_element(nums.begin(), nums.end());
        
        if(lft == rgt) return 0;
        
        double gap = 1.0*(rgt-lft)/N;
        vector<vector<int>> buckets(N+1);
        
        for(int x: nums) {
            int idx = (x-lft)/gap;
            if(buckets[idx].empty()) {
                buckets[idx].push_back(x);
                buckets[idx].push_back(x);
            } else {
                buckets[idx][0] = min(x, buckets[idx][0]);
                buckets[idx][1] = max(x, buckets[idx][1]);
            }
        }
        
        int result = 0;
        int pivot = buckets[0][1];
        for(int i=1; i<=N; i++) {
            if(!buckets[i].empty()) {
                result = max(result, buckets[i][0] - pivot);
                pivot = buckets[i][1];
            }
        }
        return result;
    }
    
    int maximumGap2(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        
        sort(nums.begin(), nums.end());
        
        int rst = INT_MIN;
        for(int i=1; i<nums.size(); i++){
            rst = max(rst, nums[i] - nums[i-1]);
        }
        
        return rst;
    }
};

// Bucket sort