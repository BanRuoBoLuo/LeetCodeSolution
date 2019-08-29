/******************************************************************************************
71. Sum of Two Integers
Easy

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3

Example 2:

Input: a = -2, b = 3
Output: 1

******************************************************************************************/


class Solution {
public:
    int getSum(int a, int b) {
        unsigned int t1 = a, t2 = b;
        while(b != 0) {
            t1 = a ^ b;
            t2 = a & b;
            
            a = t1; b = t2 << 1;
        }
        
        return a;
        
    }
};