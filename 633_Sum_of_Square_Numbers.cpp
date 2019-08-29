/******************************************************************************************
633. Sum of Square Numbers
Easy

Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

 

Example 2:

Input: 3
Output: False


******************************************************************************************/

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int lft = 0, rgt = sqrt(c);
        while(lft <= rgt) {
            int diff = c - lft*lft - rgt*rgt;
            if(diff > 0) lft ++;
            else if(diff < 0) rgt --;
            else return true;
        }
        return false;
    }
};