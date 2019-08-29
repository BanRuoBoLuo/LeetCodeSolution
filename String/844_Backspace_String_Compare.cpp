/******************************************************************************************
844. Backspace String Compare
Easy

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.

Follow up:

    Can you solve it in O(N) time and O(1) space?

******************************************************************************************/


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return absoluteString(S) == absoluteString(T);
    }
    
    string absoluteString(const string& S){
        string rst;
        
        for(char c: S) {
            if(c!='#') rst.push_back(c);
            else if(!rst.empty()) rst.pop_back();
        }
        
        return rst;
    }

    void simplifyString(string& S){
        int idx = -1;
        
        for(int i=0; i<S.size(); i++) {
            if(S[i]!='#') S[++idx] = S[i];
            else {
                if(idx >= 0) --idx;
            }
        }
        
        S.erase(idx+1); 
    }
};