/******************************************************************************************

7. Reverse Integer
Easy

Given a 32-bit signed integer, reverse digits of an integer.

-12300/10 = -1230, with mod = 0
-1230/10 = -123, with mod = 0
-123/10 = -12, with mod = -3
-12/10 = -1, with mod = -2
-1/10 = 0, with mod = -1

******************************************************************************************/

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        for (; x != 0; x /= 10)
            res = res * 10 + x % 10;
        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};

