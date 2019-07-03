/******************************************************************************************

678. Valid Parenthesis String
Medium

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
    An empty string is also valid.

*******************************************************************************************/



class Solution {
public:
    bool checkValidString(string s) {
        return validParenthesisString(s, 0, 0);
    }
    
    
    bool validParenthesisString(const string& s, int pos, int left) {
        if(left < 0) return false;
        
        if(pos == s.size()) {
            return left == 0;
        }
        
        if(s[pos] == '(') return validParenthesisString(s, pos+1, left+1) ;
        else if (s[pos] == ')') return validParenthesisString(s, pos+1, left-1);
        else if (s[pos] == '*') {
            return validParenthesisString(s, pos+1, left)  //ignore *
              || validParenthesisString(s, pos+1, left+1)  //* as left (
              || validParenthesisString(s, pos+1, left-1); //* as right )
        }
        else return false;
    }
};