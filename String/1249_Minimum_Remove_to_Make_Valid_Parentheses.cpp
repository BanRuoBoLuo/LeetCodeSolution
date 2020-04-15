/*******************************************************************************************
1249. Minimum Remove to Make Valid Parentheses
Medium

Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"

 

Constraints:

    1 <= s.length <= 10^5
    s[i] is one of  '(' , ')' and lowercase English letters.

*******************************************************************************************/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> idx;
        stack<int> p;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') p.push(i);
            else if(s[i] == ')') {
                if(p.empty()) idx.insert(i);
                else p.pop();
            }
        }
        
        while(!p.empty()) {
            idx.insert(p.top());
            p.pop();
        }
        
        string rst;
        for(int i=0; i<s.size(); i++) {
            if(idx.find(i) == idx.end()) rst.push_back(s[i]);
        }
        
        return rst;
    }
    string minRemoveToMakeValid2(string s) {
        stack<string> p;
        
        for(char c: s) {
            if(c == ')') {
                string tmp;
                while(!p.empty() && p.top() != "(") {
                    tmp = p.top() + tmp;
                    p.pop();
                }
                
                if(!p.empty() && p.top() == "(") {
                    p.pop();
                    p.push("(" + tmp + ")");
                } else if(!tmp.empty()){
                    p.push(tmp);
                }
            } else {
                p.push(string(1, c));
            }
        }
        
        string result;
        while(!p.empty()) {
            if(p.top() != "(") {
                result = p.top() + result;
            }
            p.pop();
        }
        
        return result;
    }
};