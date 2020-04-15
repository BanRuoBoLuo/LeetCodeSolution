/*******************************************************************************************
84. Largest Rectangle in Histogram
Hard

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

 
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10


*******************************************************************************************/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        heights.push_back(0);
        
        stack<int> idx; int i=0;
        while(i< heights.size()) {
            if(idx.empty() || heights[idx.top()] < heights[i]) {
                idx.push(i); i++;
            } else {
                int pos = idx.top(); idx.pop();
                int width = idx.empty()? i: i-idx.top()-1;
                result = max(result, width*heights[pos]);
            }
        }
        return result;
    }
};