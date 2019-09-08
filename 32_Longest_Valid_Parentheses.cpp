/*******************************************************************************************
32. Longest Valid Parentheses
Hard

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

*******************************************************************************************/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pos;
        pos.push(-1);
        
        int maxLen = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') pos.push(i);
            else if(s[i] == ')') {
                if(pos.top() >= 0 && s[pos.top()] == '(') {
                    pos.pop();
                    maxLen = max(maxLen, i-pos.top());
                } else {
                    pos.push(i);
                }
            }
        }
        return maxLen;
    }
};