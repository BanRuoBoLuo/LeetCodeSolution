/******************************************************************************************
31. Next Permutation
Medium

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


******************************************************************************************/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        
        int idx = nums.size()-2;
        while(idx >= 0 && nums[idx] >= nums[idx+1]) idx--;
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int pos = nums.size()-1;
        while(nums[pos] <= nums[idx]) pos--;
        
        swap(nums[idx], nums[pos]);
        reverse(nums.begin()+idx+1, nums.end());
    }
};