/******************************************************************************************
5. Longest Palindromic Substring
Medium

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

******************************************************************************************/

class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = 0;
        string rst = "";
        
        int N = s.size();
        vector<vector<bool>> dp(N, vector<bool> (N, false));
        for (int i=N-1; i>=0; i--) {
            for (int j=i; j<N; j++) {
                dp[i][j] = (j-i<2 || dp[i+1][j-1]) && s[i]==s[j];
                if(dp[i][j] && j-i+1 > len) {
                    len = j-i+1;
                    rst = s.substr(i, len);
                };
            }
        }
        return rst;
    }
};