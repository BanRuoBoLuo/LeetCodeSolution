/*************************************************************************
448. Find All Numbers Disappeared in an Array
Easy

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]


*************************************************************************/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        
        for(int i=1; i<nums.size(); i++) {
            while(nums[i] != i && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
        }
        
        vector<int> result;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != i) result.push_back(i);
        }
        return result;
    }
};