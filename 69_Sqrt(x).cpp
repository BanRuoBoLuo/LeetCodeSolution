/*******************************************************************************************
69. Sqrt(x)
Easy

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2

Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.

*******************************************************************************************/

class Solution {
public:
    //Newton's method
    //(x^2 - a)/(x-x1) = 2*x
    int mySqrt(int a) {
        if(a == 0) return 0;
        
        double x0 = a, x1 = a;
        do {
            x0 = x1;
            x1 = x0/2.0 + a/x0/2.0;
        } while(abs(x1-x0) > 0.1);
        
        return x1;
    }
};