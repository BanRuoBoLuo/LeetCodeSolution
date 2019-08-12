/*******************************************************************************************
246. Strobogrammatic Number
Easy

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true

Example 2:

Input:  "88"
Output: true

Example 3:

Input:  "962"
Output: false

*******************************************************************************************/


class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        for(int i=0, j=num.size()-1; i<=j; i++, j--){
            if(num[i]=='0' && num[j] == '0') continue;
            if(num[i]=='1' && num[j] == '1') continue;
            else if(num[i]=='8' && num[j] == '8') continue;
            else if(num[i]=='6' && num[j] == '9') continue;
            else if(num[i]=='9' && num[j] == '6') continue;
            else return false;
        }
        return true;
        
    }
};