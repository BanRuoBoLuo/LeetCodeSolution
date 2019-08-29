/*************************************************************************
349. Intersection of Two Arrays
Easy

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:

    Each element in the result must be unique.
    The result can be in any order.
*************************************************************************/
 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> stats(nums1.begin(), nums1.end());
        vector<int> result;
        for(int x: nums2) {
            if(stats.find(x) != stats.end()) {
                result.push_back(x);
                stats.erase(x);
            }
        }
        return result;
    }
    
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> stats;
        for(int x: nums1) stats[x] ++;
        
        vector<int> result;
        for(int x: nums2) {
            if(stats[x] > 0) {
                result.push_back(x);
                stats[x] = 0;
            }
        }
        return result;
    }
};