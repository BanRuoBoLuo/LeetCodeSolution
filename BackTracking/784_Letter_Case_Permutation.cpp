/*******************************************************************************************
784. Letter Case Permutation
Easy

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
*******************************************************************************************/


class Solution {
public:
    vector<string> letterCasePermutation(string S) {        
        vector<string> result;
        traverse(result, S, 0);
        
        return result;
    }
    
    void traverse(vector<string> &result, string& S, int pos) {
        
        if(pos == S.size()) {
            result.push_back(S);
            return;
        }
        
        if(!isalpha(S[pos])){
            traverse(result, S, pos+1);
        } else {
            S[pos] = tolower(S[pos]);
            traverse(result, S, pos+1);
            
            S[pos] = toupper(S[pos]);
            traverse(result, S, pos+1);
        }
    }
};