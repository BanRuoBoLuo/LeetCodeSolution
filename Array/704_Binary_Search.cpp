/******************************************************************************************
704. Binary Search
Easy

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
******************************************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int lft = 0, rgt = nums.size()-1;
        while(lft < rgt) {
            int mid = lft + (rgt-lft)/2;

            if(nums[mid] > target) rgt = mid-1;
            else if(nums[mid] < target) lft = mid+1;
            else return mid;
        }
        
        return nums[lft] == target? lft: -1;    
    }
};