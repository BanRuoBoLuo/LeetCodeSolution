/********************************************************************************************


7. Reverse Integer
Easy

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

*******************************************************************************************/

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        for (; x != 0; x /= 10)
            res = res * 10 + x % 10;
        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};