/*************************************************************************
67. Add Binary
Easy

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*************************************************************************/


class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size()) return addBinary(b, a);
        
        a.insert(0, b.size()-a.size(), '0');
        
        int carry = 0;
        string result(a.size(), '0');
        for(int i=a.size()-1; i>=0; i--) {
            carry = (a[i]-'0') + (b[i] - '0') + carry;
            
            result[i] = '0' + (carry%2);
            carry = carry/2;
        }
        
        if(carry == 1) return "1"+result;
        return result;
        
    }
};