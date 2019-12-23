/*************************************************************************
215. Kth Largest Element in an Array
Medium

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.


*************************************************************************/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        
        return findKthNum(nums, 0, nums.size()-1, nums.size()-k);
    }
    
    int findKthNum(vector<int>& nums, int lft, int rgt, int k) {
        int q = partition(nums, lft, rgt);
        
        if(q == k) return nums[q];
        else if (q < k) return findKthNum(nums, q+1, rgt, k);
        else return findKthNum(nums, lft, q-1, k);
    }
    
    
    int partition(vector<int>& nums, int lft, int rgt) {
        if(lft == rgt) return rgt;
        
        int pivot = nums[rgt];
        
        int idx = lft;
        for(int i=lft; i<rgt; i++) {
            if(nums[i] < pivot) {
                swap(nums[i], nums[idx++]);
            }
        }
        swap(nums[rgt], nums[idx]);
        return idx;
    }
};