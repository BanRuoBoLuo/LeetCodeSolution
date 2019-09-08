/******************************************************************************************
22. Generate Parentheses
Medium

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

******************************************************************************************/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> rst(n+1);
        
        rst[0].push_back("");
        for(int k=1; k<=n; k++){
            for(int i=0; i<k; i++){
                for(string s: rst[i]) 
                    for(string r: rst[k-i-1]){
                        rst[k].push_back("(" +s+")"+r);
                    }
            }
        }
        return rst[n];
    }
};