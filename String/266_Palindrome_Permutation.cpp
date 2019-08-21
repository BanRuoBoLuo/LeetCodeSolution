/*******************************************************************************************
266. Palindrome Permutation
Easy

Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false

Example 2:

Input: "aab"
Output: true

Example 3:

Input: "carerac"
Output: true

*******************************************************************************************/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        unordered_map<char, int> count;
        for(char c: s) count[c] ++;
        
        int cnt = 0;
        for(auto it = count.begin(); it != count.end(); ++it) {
            if(it->second %2 != 0) cnt ++;
            if(cnt > 1) return false;
        }
        return true;
    }
};