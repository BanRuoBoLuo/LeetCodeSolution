/*************************************************************************
1185. Day of the Week
Easy

Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

 

Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"

Example 2:

Input: day = 18, month = 7, year = 1999
Output: "Sunday"

Example 3:

Input: day = 15, month = 8, year = 1993
Output: "Sunday"

 

Constraints:

    The given dates are valid dates between the years 1971 and 2100.

*************************************************************************/


class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        //1971-1-1 Friday
        int DaysByMonthMod7[12] = {0,3,2,5,0,3,5,1,4,6,2,4}; // 2
        if(month < 3) year -= 1; // 3
        return days[(year + year/4 - year/100 + year/400 + DaysByMonthMod7[month-1] + day) % 7]; // 4
    }
    
};