/*******************************************************************************************
50. Pow(x, n)
Medium

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]


*******************************************************************************************/

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(x == 1 || n == 0) return 1;

        bool negative = x < 0 && n%2 != 0;
        bool reverse = n < 0;
        
        double rst = myPowerHelper(abs(x), abs(n));
        if (reverse) {
            rst = 1.0/rst;
        }
        
        return negative? -rst: rst;
    }
    
    
    double myPowerHelper(double x, unsigned int n) {
        if(n == 1) return x;
        if(n == 0) return 1;
        
        double rst = n%2 == 0? 1: x;
        double r = myPowerHelper(x, n/2);
        return rst * r * r;
    }
};