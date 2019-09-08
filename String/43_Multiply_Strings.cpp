/*******************************************************************************************
43. Multiply Strings
Medium

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

Note:

    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

*******************************************************************************************/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        string result;
        
        for(char c: num2) {
            result.push_back('0');
            result = addString(result, multiplyDigit(num1, c));
        }
        
        return result;
    }
    
    
    string multiplyDigit(string num, char c) {
        if(c == '0') return "0";
        int carry = 0;
        string result;
        
        for(int i=num.size()-1; i>=0; i--){
            carry += (num[i]-'0')*(c-'0');
            result.push_back('0'+carry%10);
            carry = carry/10;
        }
        if(carry != 0) result.push_back('0'+carry);
        reverse(result.begin(), result.end());
        return result;
    }
    
    string addString(string a, string b){        
        if(a.size() > b.size()) return addString(b, a);
        if(a == "0") return b;
        
        string result;
        
        a = string(b.size()-a.size(), '0') + a;
        int carry = 0;
        for(int i=b.size()-1; i>=0; i--) {
            carry += (b[i]-'0') + (a[i]-'0');
            result.push_back(carry%10 + '0');
            carry = carry/10;
        }
        if(carry != 0) result.push_back('0'+carry);
        reverse(result.begin(), result.end());
        return result;
    }
};