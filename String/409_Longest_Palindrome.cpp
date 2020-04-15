/*******************************************************************************************
409. Longest Palindrome
Easy

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*******************************************************************************************/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for(char c: s) {
            cnt[c] ++;
        }
        
        int len = 0; bool odd = false;
        for(auto it = cnt.begin(); it != cnt.end(); ++it) {
            if(it->second % 2 == 0) len += it->second;
            else {
                odd = true;
                len += it->second -1;
            }
        }
        
        return odd? len +1 : len;
        
    }
};