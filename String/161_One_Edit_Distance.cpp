/*******************************************************************************************
161. One Edit Distance
Medium

Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

    Insert a character into s to get t
    Delete a character from s to get t
    Replace a character of s to get t

Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.

Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.

*******************************************************************************************/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int idx =0;
        while(idx<s.size() && idx < t.size() && s[idx] == t[idx]) idx++;
        
        string rs = s.substr(idx);
        string rt = t.substr(idx);
        
        if(rs.empty() && rt.empty()) return false;
        if(rs.empty()) return rt.size() == 1;
        else if(rt.empty()) return rs.size() == 1;
        
        return rs.substr(1) == rt.substr(1) || rs == rt.substr(1) || rs.substr(1) == rt;
    }
};

