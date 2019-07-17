/******************************************************************************************
26. Remove Duplicates from Sorted Array
Easy

Given a sorted array nums, remove the duplicates in-place 
such that each element appear only once and return the new length.

Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.

*******************************************************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        
        int pivot = nums[0];
        int pos = 1;
        for(int idx = 1; idx < nums.size(); idx++) {
            if(nums[idx] != pivot) {
                pivot = nums[idx];
                nums[pos] = pivot; pos ++;
            }
        }
        return pos;

    }

    //using std::unique
    int removeDuplicates2(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        return distance(nums.begin(), it);
    }
};