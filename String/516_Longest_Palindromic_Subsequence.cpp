/*******************************************************************************************
516. Longest Palindromic Subsequence
Medium

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"

Output:

4

One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:

"cbbd"

Output:

2

One possible longest palindromic subsequence is "bb". 

*******************************************************************************************/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int N = s.size();
        vector<vector<int>> dp(N+1, vector<int> (N+1, 0));
        for (int i=0; i<N; i++) {
            for (int j = 0; j<N; j++) {
                if (s[i] == rev[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[N][N];
    }
};