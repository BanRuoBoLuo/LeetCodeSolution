/*******************************************************************************************
788. Rotated Digits
Easy

X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

*******************************************************************************************/

class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for(int i=2; i<=N; i++){
            if(isGoodNumber(i)) cnt ++;
        }
        return cnt;
    }
    
    bool isGoodNumber(int x) {
        if(x <= 0) return false;
        
        int num = x, rst = 0, base = 1;
        while(num>0) {
            int digit = num%10;
            num = num/10; 
            
            if(digit== 3 || digit == 4 || digit == 7) return false;
            rst += rotate[digit]*base; base *= 10;
        }
        return rst != x;
    }
    
    vector<int> rotate{0, 1, 5, 0, 0, 2, 9, 0, 8, 6};
};