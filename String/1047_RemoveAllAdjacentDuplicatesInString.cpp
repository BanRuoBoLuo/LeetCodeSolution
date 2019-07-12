/*******************************************************************************************
1047. Remove All Adjacent Duplicates In String
Easy

Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.
*******************************************************************************************/
#include <algorithm>
#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        
        for(char c : S) {
            if(!stk.empty() && stk.top() == c) {
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }
        
        string str("");
        while(!stk.empty()) {
            str.push_back(stk.top());
            stk.pop();
        }
        reverse(str.begin(), str.end());
        return str;
        
    }
};