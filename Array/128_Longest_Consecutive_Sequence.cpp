/*******************************************************************************************
128. Longest Consecutive Sequence
Hard

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


*******************************************************************************************/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, bool> used;
        for(int x: nums) used[x] = false;
        
        int rst = 0;
        for(int x: nums) {
            if(used[x]) continue;
            
            int length = 1;
            for(int j=x+1; used.find(j) != used.end(); j++) {
                used[j] = true;
                length ++;
            }
            
            for(int j=x-1; used.find(j) != used.end(); j--) {
                used[j] = true;
                length ++;
            }
            
            rst = max(rst, length);
        }
        
        return rst;
    }
};