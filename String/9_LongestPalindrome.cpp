/******************************************************************************************409. Longest Palindrome
Easy

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010. 
******************************************************************************************/

class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> cnt;
        for(char c: s) cnt[c] ++;
        
        bool odd = false;
        int length=0;
        
        for (auto x : cnt){
            if(x.second % 2 == 0) length += x.second;
            else {
                odd = true;
                length += x.second-1;
            }
        }
        
        return odd? length + 1: length;
    }
};