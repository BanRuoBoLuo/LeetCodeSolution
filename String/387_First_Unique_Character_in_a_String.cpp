/*************************************************************************
387. First Unique Character in a String
Easy

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters. 

*************************************************************************/



class Solution {
public:
    int firstUniqChar(string s) {        
        vector<int> letters(26, -1);
        
        for(int i=0; i<s.size(); i++) {
            if (letters[s[i]-'a'] == -1) letters[s[i]-'a'] = i;
            else if (letters[s[i]-'a'] >= 0) letters[s[i]-'a'] = -2;
        }
        
        int result = s.size();
        for(int x: letters) {
            if(x >= 0) result = min(result, x);
        }
        return result == s.size()? -1: result;
    }
};