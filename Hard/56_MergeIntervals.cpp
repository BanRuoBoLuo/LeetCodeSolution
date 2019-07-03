/******************************************************************************************
56. Merge Intervals
Medium

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
******************************************************************************************/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start == b.start ? a.end < b.end: a.start < b.start;
        });
        
        vector<Interval> result;
        
        for (Interval& it : intervals) {
            if(result.empty() || result.back().end < it.start) {
                result.push_back(it);
            }
            else {
                result.back().end = max(result.back().end, it.end);
            }
        }
        
        return result;  
    }
};