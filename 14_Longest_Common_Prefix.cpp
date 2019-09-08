/*******************************************************************************************
14. Longest Common Prefix
Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:

All given inputs are in lowercase letters a-z.

*******************************************************************************************/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        string result = strs[0];
        int len = 0;
        for(; len<result.size(); len++){
            for(int j=1; j<strs.size(); j++){
                if(len >= strs[j].size() || strs[j][len] != result[len]) return result.substr(0, len);
            }
        }
        return result.substr(0, len);
    }
};