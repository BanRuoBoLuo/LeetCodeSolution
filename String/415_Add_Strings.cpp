/*******************************************************************************************

415. Add Strings
Easy

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.


*******************************************************************************************/

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size()) return addStrings(num2, num1);
        
        num2 = string(num1.size()-num2.size(), '0') + num2;
        int carry = 0;
        
        for(int i=num1.size()-1; i>=0; i--){
            carry += num1[i]-'0' + num2[i]-'0';
            num1[i] = carry%10 +'0';
            carry = carry/10;
        }
        
        if(carry > 0) return string(1, carry+'0') + num1;
        return num1;
        
    }
};