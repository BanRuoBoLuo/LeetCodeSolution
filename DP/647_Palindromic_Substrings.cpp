/*******************************************************************************************
647. Palindromic Substrings
Medium

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*******************************************************************************************/

class Solution {
public:
    int countSubstrings(string s) {
        
        size_t N = s.size();
        vector<vector<bool>> dp(N, vector<bool> (N, false));
        
        int cnt = 0;
        for(int j = 0; j<N; j++) {
            for(int i=0; i<=j; i++) {
                dp[i][j] = (j-i <= 2 || dp[i+1][j-1]) && s[i] == s[j];
                if(dp[i][j]) cnt ++;
            }
        }
        
        return cnt;
    }
};