/******************************************************************************************
680. Valid Palindrome II
Easy

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:

Input: "aba"
Output: True

Example 2:

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:

    The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

******************************************************************************************/


class Solution {
public:
    bool validPalindrome(string s) {
        return isValid(s, 0, s.size()-1, 0);
    }
    
    bool isValid(const string& s, int left, int right, int cnt) {
        if(cnt > 1) return false;
        
        while(left < right && s[left] == s[right]) {
            left ++ ;
            right --;
        }
        
        if(left >= right) return true;
        return isValid(s, left+1, right, cnt+1) || isValid(s, left, right-1, cnt+1);
    }
};