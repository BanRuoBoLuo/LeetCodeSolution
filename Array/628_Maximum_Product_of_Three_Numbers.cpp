/*******************************************************************************************
628. Maximum Product of Three Numbers
Easy

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6

 

Example 2:

Input: [1,2,3,4]
Output: 24

 

Note:

    The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
    Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.


*******************************************************************************************/

class Solution {
public:
    int maximumProduct2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t sz = nums.size();
        int a = nums[sz-1] * nums[sz-2] * nums[sz-3];
        int b = nums[0] * nums[1] * nums[sz-1];
        return max(a, b);
    }
    
    int maximumProduct(vector<int>& nums) {
        int a=INT_MIN, b=a, c=b;
        int x=INT_MAX, y=c;
        for (int i : nums) {
            if (i>a) {
                c = b;
                b = a;
                a = i;
            } else if (i>b) {
                c = b;
                b = i;
            } else if (i>c) c=i;
            
            if(i<x) {
                y = x;
                x = i;
            } else if (i<y) y=i;
        }
        return max(x*y*a, a*b*c);
    }
};