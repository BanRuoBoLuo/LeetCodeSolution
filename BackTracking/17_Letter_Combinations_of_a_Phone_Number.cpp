/******************************************************************************************
17. Letter Combinations of a Phone Number
Medium

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.

******************************************************************************************/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string> {};
        
        string path;
        vector<string> result;
        
        dfs(digits, 0, path, result);
        return result;
    }
    
    void dfs(const string& digits, int idx, string& path, vector<string>& result ) {
        if (idx == digits.size()) {
            result.push_back(path);
            return;
        }
        
        int num = digits[idx]-'0';
        for(char c : cmb[num]) {
            path.push_back(c);
            dfs(digits, idx+1, path, result);
            path.pop_back();
        }
    }
    
    vector<string> cmb{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
};