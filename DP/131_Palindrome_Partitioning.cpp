/*******************************************************************************************
131. Palindrome Partitioning
Medium

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]

*******************************************************************************************/


class Solution {
public:
    vector<vector<string>> partition(const string& s) {
             
        int N = s.size();
        vector<vector<bool>> dp(N, vector<bool> (N, false));
        
        for(int i=N-1; i>=0; i--) {
            for(int j=i; j<N; j++) {
                dp[i][j] = s[i] == s[j] && (j-i < 2 || dp[i+1][j-1]);
            }
        }
        
        vector< vector<vector<string>>> result(N);
        
        for(int i=N-1; i>=0; i--) {
            for(int j=i; j<N; j++) {
                if(!dp[i][j]) { 
                    continue;
                }
                // s[i...j] is palindrome
                string sij = s.substr(i, j-i+1);
                if(j == N-1) {
                    result[i].push_back(vector<string> {sij});
                } else {
                    for(auto v: result[j+1]) {
                        v.insert(v.begin(), sij);
                        result[i].push_back(v);
                    }
                }
            }
        }
        
        return result[0];   
    }
};