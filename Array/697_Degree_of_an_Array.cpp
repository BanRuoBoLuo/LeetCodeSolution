/*******************************************************************************************
697. Degree of an Array
Easy

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:

Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:

Input: [1,2,2,3,1,4,2]
Output: 6

Note:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.


*******************************************************************************************/


class Solution {
public:
    struct Occurence {
        int cnt;
        int lft, rgt;
        
        Occurence(): cnt(0), lft(0), rgt(0) {}
        Occurence(int idx): cnt(1), lft(idx), rgt(idx) {}
    };
    
    int findShortestSubArray(vector<int>& nums) {
        int degree = 0;
        unordered_map<int, Occurence> D;
        for(int i=0; i<nums.size(); i++) {
            if(D.find(nums[i]) == D.end()) {
                D[nums[i]] = Occurence(i);
                degree = max(degree, 1);
            } else {
                D[nums[i]].cnt++;
                D[nums[i]].rgt = i;
                
                degree = max(degree, D[nums[i]].cnt);
            }
        }
        int result = nums.size();
        for(auto it = D.begin(); it != D.end(); ++it) {
            if(it->second.cnt == degree) result = min(it->second.rgt - it->second.lft + 1, result);
        }
        return result;
    }

};