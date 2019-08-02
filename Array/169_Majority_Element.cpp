/******************************************************************************************
169. Majority Element
Easy

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

******************************************************************************************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        return findKthNumber(nums, 0, N-1, N/2);
    }
    
    int findKthNumber(vector<int>& nums, int lft, int rgt, int K) {
        int q = partition(nums, lft, rgt);
        if(q < K) return findKthNumber(nums, q+1, rgt, K);
        else if(q > K) return findKthNumber(nums, lft, q-1, K);
        else return nums[K];
    } 
    
    int partition(vector<int>& nums, int lft, int rgt) {
        int pivot = nums[rgt];
        int idx = lft;
        for(int i=lft; i<rgt; i++) {
            if(nums[i] < pivot) {
                swap(nums[idx], nums[i]);
                idx++;
            }
        }
        swap(nums[idx], nums[rgt]);
        return idx;
    }


    /// Boyer-Moore Voting Algorithm
    int majorityElement2(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int cnt = 0, majority = -1;
        for(int x : nums) {
            if (cnt == 0) {majority = x; cnt = 1;}
            else if (majority == x) cnt ++;
            else cnt --;
        }
        
        return majority;
    }
};