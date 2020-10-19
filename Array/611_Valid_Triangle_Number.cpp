/*******************************************************************************************
611. Valid Triangle Number
Medium
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:

Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Note:

    The length of the given array won't exceed 1000.
    The integers in the given array are in the range of [0, 1000].
    
*******************************************************************************************/



class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int i=0;
        while(i<nums.size() && nums[i] <= 0) i++;
        for(; i<nums.size()-2; i++) {
            int k = i+2;
            for(int j=i+1; j<nums.size()-1; j++) {
                
                while(k < nums.size() && nums[i] + nums[j] > nums[k]) k++;
                count += k-j-1;
            }
        }
        
        return count;
    }
};