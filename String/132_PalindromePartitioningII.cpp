/******************************************************************************************
132. Palindrome Partitioning II
Hard

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*****************************************************************************************/

class Solution {
public:
    int minCut(string s) {
        
        size_t N = s.size();
        vector<vector<bool>> dp(N, vector<bool> (N, false));        
        for(int i=N-1; i>=0; i--) {
            for(int j=i; j<N; j++) dp[i][j] = (j-i < 2 || dp[i+1][j-1]) && s[i]==s[j];
        }
        
        vector<int> cuts(N, N);
        for(int i=0; i<N; i++) {
            if(dp[0][i]) cuts[i] = 0;
            else {
                for(int j = 1; j<=i; j++) {
                    if(dp[j][i]) cuts[i] = min(cuts[i], cuts[j-1]+1);
                }
            }
        }
        return cuts[N-1];
    }
};