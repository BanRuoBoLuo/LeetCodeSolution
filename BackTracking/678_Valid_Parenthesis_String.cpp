/*******************************************************************************************
678. Valid Parenthesis String
Medium

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
    An empty string is also valid.

Example 1:

Input: "()"
Output: True

Example 2:

Input: "(*)"
Output: True

Example 3:

Input: "(*))"
Output: True

Note:

    The string size will be in the range [1, 100].


/*******************************************************************************************


class Solution {
public:
    bool checkValidString(string s) {
        return traverse(s, 0, 0);
    }
    
    bool traverse(const string& s, int pos, int cnt) {
        if(cnt < 0) return false;
        if(s.size() == pos) return cnt == 0;
        
        int idx = pos;
        for(; idx<s.size(); idx++) {
            if(s[idx] == '(') cnt ++;
            else if(s[idx] == ')') {
                cnt --;
                if(cnt < 0) return false;
            } 
            else break;
        }
        
        if(idx < s.size())
            return traverse(s, idx+1, cnt) ||
            traverse(s, idx+1, cnt+1) ||
            traverse(s, idx+1, cnt-1) ;
        
        return cnt == 0;
    }
};