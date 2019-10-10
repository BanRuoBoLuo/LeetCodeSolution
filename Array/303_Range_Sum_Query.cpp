/*******************************************************************************************
303. Range Sum Query - Immutable
Easy

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:

    You may assume that the array does not change.
    There are many calls to sumRange function.

*******************************************************************************************/


class NumArray {
public:
    NumArray(vector<int>& nums) {
        total = std::accumulate(nums.begin(), nums.end(), 0);
        
        left = vector<int> (nums.size(), 0);
        right= vector<int> (nums.size(), 0);
        
        for(int i=1; i<nums.size(); i++){
            left[i] = left[i-1]+nums[i-1];
        }
        
        for(int i=nums.size()-2; i>=0; i--) {
            right[i] = right[i+1] + nums[i+1];
        }
    }
    
    int sumRange(int i, int j) {
        return total - left[i] - right[j];
    }
    
    vector<int> left;
    vector<int> right;
    int total;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */