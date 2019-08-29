/*******************************************************************************************
1056. Confusing Number
Easy

Given a number N, return true if and only if it is a confusing number, which satisfies the following condition:

We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

 

Example 1:

Input: 6
Output: true
Explanation: 
We get 9 after rotating 6, 9 is a valid number and 9!=6.

Example 2:

Input: 89
Output: true
Explanation: 
We get 68 after rotating 89, 86 is a valid number and 86!=89.

*******************************************************************************************/


class Solution {
public:
    bool confusingNumber(int N) {
        int rst = 0, ori = N;
        while(N > 0){
            int d = N%10;
            if(d==2 || d == 3|| d == 4|| d ==5 || d==7) return false;
            
            rst = rst *10 + rotate[d];
            N = N/10;
        }
        return ori != rst;
    }
    
    vector<int> rotate{0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
};