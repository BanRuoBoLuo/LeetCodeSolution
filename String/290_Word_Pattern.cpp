/*******************************************************************************************
290. Word Pattern
Easy

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.

*******************************************************************************************/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        
        stringstream ss(str);
        string wd;
        while(ss >> wd) {
            words.push_back(wd);
        }
        
        if(words.size() != pattern.size()) return false;
        
        unordered_map<char, string> patternStr;
        unordered_map<string, char> strPattern;
        
        for(int i=0; i<pattern.size(); i++) {
            if(patternStr.find(pattern[i])==patternStr.end() && strPattern.find(words[i]) == strPattern.end()){
                patternStr[pattern[i]] = words[i];
                strPattern[words[i]] = pattern[i];
            } else {
                if (patternStr[pattern[i]] != words[i] || strPattern[words[i]] != pattern[i]) return false;
            }
        }
        
        return true;
    }
};