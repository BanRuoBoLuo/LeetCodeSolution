/*******************************************************************************************
58. Length of Last Word
Easy

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5

*******************************************************************************************/


class Solution {
public:
    int lengthOfLastWord(string s) {
        
        size_t last = s.find_last_not_of(' ');
        if(last == string::npos) return 0;
        
        size_t space = s.find_last_of(' ', last);
        if(space == string::npos) return last+1;
        
        return last - space; 
    }
};