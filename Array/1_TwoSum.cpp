/******************************************************************************************
1. Two Sum
Easy

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*******************************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> idx;
        
        for(int i=0; i<nums.size(); i++) {
            int x = target - nums[i];
            if(idx.find(x) == idx.end()) {
                idx[nums[i]] = i; 
            }
            else {
                return vector<int> {idx[x], i};
            }
        }
        
        return vector<int> {};
        
    }
};