/******************************************************************************************
57. Insert Interval
Hard

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        vector<Interval> rst{newInterval};
        int idx = 0;
        for(auto iter: intervals) {
            if(iter.end < rst.back().start){
                rst.insert(rst.begin()+idx, iter);
                idx ++;
            }
            else if ( iter.start > rst.back().end) {
                rst.push_back(iter);
            }
            else {
                rst.back().start = min(rst.back().start, iter.start);
                rst.back().end = max(rst.back().end, iter.end);
            }
        }
        
        return rst;
    }
};