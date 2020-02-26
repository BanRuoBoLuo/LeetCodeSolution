/******************************************************************************************
239. Sliding Window Maximum
Hard

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

******************************************************************************************/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> rst;
        if(nums.empty()) return rst;
        
        std::deque<int> idx;
        for(int i=0; i<k; i++) {
            updateSlideWindow(idx, nums, i);
        }
        
        rst.push_back(nums[idx.front()]);
        
        for(int i=k; i<nums.size(); i++){
            if(idx.front() < i+1-k) idx.pop_front();
            
            updateSlideWindow(idx, nums, i);
            rst.push_back(nums[idx.front()]);
        }
        
        return rst;
    }
    
    void updateSlideWindow(std::deque<int>& idx, const vector<int>& nums, int pos) {
        if(pos < 0 || pos >= nums.size()) return;
        
        if(idx.empty() || nums[idx.back()] > nums[pos]) {
            idx.push_back(pos);
            return;
        } 
        while (!idx.empty() && nums[idx.back()] <= nums[pos]) {
            idx.pop_back();
        }
        idx.push_back(pos);
    }
};