/*******************************************************************************************
551. Student Attendance Record I
Easy
You are given a string representing an attendance record for a student. The record only contains the following three characters:

    'A' : Absent.
    'L' : Late.
    'P' : Present.

A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:

Input: "PPALLP"
Output: True

Example 2:

Input: "PPALLL"
Output: False

*******************************************************************************************/


class Solution {
public:
    bool checkRecord(string s) {
        int Acnt=0; int Lcnt = 0;
        for(char c: s) {
            if(c == 'A') {Acnt++; Lcnt =0;}
            else if (c == 'L') Lcnt++;
            else {Lcnt = 0;}
            
            if(Lcnt > 2) return false;
        }
        
        return Acnt < 2;
    }
};