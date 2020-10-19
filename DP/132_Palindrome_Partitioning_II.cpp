/*******************************************************************************************
132. Palindrome Partitioning II
Hard

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

*******************************************************************************************/



class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        
        vector<int> rst(N+1, 0);
        for(int i=0; i<=N; i++) rst[i] = N-1-i;
        vector<vector<bool>> dp(N, vector<bool> (N, false));
        for(int i=N-1; i>=0; i--) {
            for(int j=i; j<N; j++) {
                dp[i][j] = s[i] == s[j] && (j-i<2 || dp[i+1][j-1]);
                if(dp[i][j]) {
                    rst[i] = min(rst[i], rst[j+1]+1);
                }
            }
        }
        
        return rst[0];
    }
};