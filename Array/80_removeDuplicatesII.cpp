/******************************************************************************************
80. Remove Duplicates from Sorted Array II
Medium

Given a sorted array nums, remove the duplicates in-place such that duplicates appeared 
at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input 
array in-place with O(1) extra memory.

*******************************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        
        int idx = 1;
        for(int i=2; i<nums.size(); i++) {
            if(nums[i] != nums[idx-1]) { //comparing to 2-pos before the test num
                nums[++idx] = nums[i];
            }
        }
        
        return idx+1;
    }
};