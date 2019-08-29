/*******************************************************************************************
541. Reverse String II
Easy

Given a string and an integer k, you need to reverse the first k characters for every 2k 
characters counting from the start of the string. If there are less than k characters left, 
reverse all of them. If there are less than 2k but greater than or equal to k characters, 
then reverse the first k characters and left the other as original.

Example:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:

    The string consists of lower English letters only.
    Length of the given string and k will in the range [1, 10000]


*******************************************************************************************/

class Solution {
public:
    string reverseStr(string s, int k) {
        size_t pos = 0;
        while(pos<s.size() && pos + k < s.size()) {
            reverse(s.begin()+pos, s.begin()+k+pos);
            pos += k*2;
        }
        
        if(pos<s.size()) reverse(s.begin()+pos, s.end());
        return s;
    }
};