/*******************************************************************************************
301. Remove Invalid Parentheses
Hard

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]

Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]

Example 3:

Input: ")("
Output: [""]


*******************************************************************************************/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int invalid_lft = 0, invalid_rgt = 0;
        int cnt = 0;
        for(char c : s) {
            if (c == '(') cnt ++;
            else if (c ==')') cnt --;
            
            if(cnt < 0) {
                invalid_rgt ++;
                cnt = 0;
            }
        }
        
        invalid_lft = cnt;

        string path;
        unordered_set<string> result;
        traverse(s, 0, 0, invalid_lft, invalid_rgt, path, result);
        
        return vector<string> (result.begin(), result.end()) ;
    }
    
    void traverse(const string& s, int pos, int count, int invalid_lft, int invalid_rgt, string& path, unordered_set<string> &result) {
        if(pos == s.size()) {
            if(count == 0 && invalid_lft ==0 && invalid_rgt == 0) {
                result.insert(path);
            }
            return;
        }
        
        if(count < 0) return;
        
        if(s[pos] == '(') {
            if(invalid_lft > 0) {
                // delete this (
                traverse(s, pos+1, count, invalid_lft-1, invalid_rgt, path, result);
            }
            
            path.push_back('(');
            traverse(s, pos+1, count+1, invalid_lft, invalid_rgt, path, result);
            path.pop_back();
        } else if (s[pos] == ')') {
            if(invalid_rgt > 0) {
                // delete this (
                traverse(s, pos+1, count, invalid_lft, invalid_rgt-1, path, result);
            }
            
            path.push_back(')');
            traverse(s, pos+1, count-1, invalid_lft, invalid_rgt, path, result);
            path.pop_back();
        } else {
            path.push_back(s[pos]);
            traverse(s, pos+1, count, invalid_lft, invalid_rgt, path, result);
            path.pop_back();
        }
           
    }
};