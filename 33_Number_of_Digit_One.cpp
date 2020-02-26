/*************************************************************************
33. Number of Digit One
Hard

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example:

Input: 13
Output: 6 
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

*************************************************************************/

class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        else if (n <= 9) return 1;
        
        int base = 1, dgt = 0;
        while(n/base > 9) {
            base *= 10; dgt ++;
        }
        
        int lft = n/base, rmd = n%base;
        
        int total = base/10*dgt*lft;
        if(lft > 1) total += base;
        else total += rmd+1;
        
        return total + countDigitOne(rmd);
    }
};