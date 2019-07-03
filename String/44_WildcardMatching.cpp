/******************************************************************************************
44. Wildcard Matching
Hard

Given an input string (s) and a pattern (p), 
implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like ? or *.
*******************************************************************************************/

class Solution {
public:
    bool isMatch(string s, string p) {
        int N = s.size(), M = p.size();
        vector<vector<bool>> dp(N+1, vector<bool> (M+1, false));
        
        dp[0][0] = true;
        for(int i=0; i<M; i++) dp[0][i+1] = dp[0][i] && p[i]=='*';
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++){
                //case 1: s[i] == p[j]  return match result of s[i-1] p[j-1]
                //case 2: p[j] == '*'   match s[i] && p[j-1]  // ignore p[j]
                //                         or s[i-1] && p[j]  // ignore s[j]
                dp[i+1][j+1] = (dp[i][j] && (s[i] == p[j] || p[j]=='?')) || 
                    (p[j] == '*' && (dp[i][j+1] || dp[i+1][j] ));
            }
        }
        
        return dp[N][M];
    }
};