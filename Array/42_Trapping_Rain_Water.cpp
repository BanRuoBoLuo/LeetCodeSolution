/*******************************************************************************************
42. Trapping Rain Water
Hard

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*******************************************************************************************/

class Solution {
public:
    
    // use stack
    int trap(vector<int>& height) {
        
    }
    
    // find largest on left and right
    int trap2(vector<int>& height) {
        int N = height.size();
        vector<int> left(height), right(height);
        
        for(int i=1; i<N; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        
        for(int i=N-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }
        
        int x = 0;
        for(int i=0; i<N; i++) {
            x += min(left[i], right[i]) - height[i];
        }
        return x;
    }
    
    
};