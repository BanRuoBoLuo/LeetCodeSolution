/*******************************************************************************************
205. Isomorphic Strings
Easy

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

Note:
You may assume both s and t have the same length.

*******************************************************************************************/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        
        for(int i=0; i<s.size(); i++) {
            if(s2t.find(s[i]) == s2t.end() && t2s.find(t[i]) == t2s.end()){
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if(s2t[s[i]] != t[i] || t2s[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
        
    }
};