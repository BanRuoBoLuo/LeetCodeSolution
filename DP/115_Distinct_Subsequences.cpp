/*******************************************************************************************
115. Distinct Subsequences
Hard

Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It's guaranteed the answer fits on a 32-bit signed integer.

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^

Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^

*******************************************************************************************/

class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.empty() || s.empty()) return 0;
        
        int M = t.size(), N = s.size();
        
        vector<vector<long long>> dp(M, vector<long long> (N, 0));
        dp[0][0] = s[0] == t[0] ? 1: 0;
        
        for(int j=1; j<N; j++) {
            dp[0][j] = (t[0] == s[j]? 1: 0) + dp[0][j-1];
        }
        
        for(int i=1; i<M; i++) {
            for(int j=i; j<N; j++) {
                if(t[i] == s[j]) dp[i][j] = dp[i-1][j-1];
                dp[i][j] += dp[i][j-1];
            }
        }
        
        return dp[M-1][N-1];
    }
};