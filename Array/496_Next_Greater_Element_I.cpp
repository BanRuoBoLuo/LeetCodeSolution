/*******************************************************************************************
496. Next Greater Element I
Easy

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.

Note:

    All elements in nums1 and nums2 are unique.
    The length of both nums1 and nums2 would not exceed 1000.
*******************************************************************************************/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> num;
        for(int x: nums2){
            while(!num.empty() && num.top() < x){
                nextGreater[num.top()] = x;
                num.pop();
            }
            num.push(x);
        }
        
        while(!num.empty()){
            nextGreater[num.top()] = -1;
            num.pop();
        }
        
        vector<int> result;
        for(int x: nums1){
            result.push_back(nextGreater[x]);
        }
        return result;
    }

    vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
        //traverse right to left
        unordered_map<int, int> nextGreater;
        stack<int> nextGreaterStack;
        
        for(int i=nums2.size()-1; i>=0; i--) {
            while(!nextGreaterStack.empty() && nextGreaterStack.top() <= nums2[i]) {
                nextGreaterStack.pop();
            }
            
            if(nextGreaterStack.empty()) {
                nextGreater[nums2[i]] = -1;
            } else {
                nextGreater[nums2[i]] = nextGreaterStack.top();
            }
            nextGreaterStack.push(nums2[i]);
        }
        
        vector<int> result;
        for(int x: nums1){
            result.push_back(nextGreater[x]);
        }
        return result;
    }
};