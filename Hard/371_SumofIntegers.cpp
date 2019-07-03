/******************************************************************************************

371. Sum of Two Integers
Easy

Calculate the sum of two integers a and b, but you are not allowed to use the 
operator + and -.

******************************************************************************************/


class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;
        
        return getSum(a^b, (a&b)<<1);
    }
};