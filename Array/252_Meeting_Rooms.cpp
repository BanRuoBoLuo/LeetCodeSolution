/*******************************************************************************************
252. Meeting Rooms
Easy

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false

Example 2:

Input: [[7,10],[2,4]]
Output: true


*******************************************************************************************/


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return true;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0]? a[1] < b[1]: a[0] < b[0];
        });
        
        for(int i=0; i<intervals.size()-1; i++){
            if(intervals[i][1] > intervals[i+1][0]) return false;
        }
        return true;
    }
};