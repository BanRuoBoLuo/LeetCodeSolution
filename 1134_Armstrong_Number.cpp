/*********************************************************************************************

1134. Armstrong Number
Easy

The k-digit number N is an Armstrong number if and only if the k-th power of each digit sums to N.

Given a positive integer N, return true if and only if it is an Armstrong number.

 

Example 1:

Input: 153
Output: true
Explanation: 
153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.

Example 2:

Input: 123
Output: false
Explanation: 
123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.

 *********************************************************************************************/


class Solution {
public:
    bool isArmstrong(int N) {
        if(N <= 0) return false;
        
        vector<int> digits = int2Digits(N);
        int n = digits.size();
        
        int x = accumulate(digits.begin(), digits.end(), 0, [n](int s, int a){return s + pow(a, n);});
        return x == N;
    }
    
    vector<int> int2Digits(int N) {
        
        vector<int> res;
        while(N > 0) {
            res.push_back(N%10);
            N = N/10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};