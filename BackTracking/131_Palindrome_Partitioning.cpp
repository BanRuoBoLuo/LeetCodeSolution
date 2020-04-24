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
        
        vector<string> path;
        vector<vector<string>> result;
        dfs(s, 0, dp, path, result);
        
        return result;
    }
    
    void dfs(const string& s, int pos, const vector<vector<bool>>& dp, vector<string> &path, vector<vector<string>> &result) {
        if(pos == s.size()) {
            result.push_back(path);
            return;
        }
        
        for(int i=pos; i<s.size(); i++) {
            if(dp[pos][i]) {
                path.push_back(s.substr(pos, i-pos+1));
                
                dfs(s, i+1, dp, path, result);
                path.pop_back();
            }
        }
    }
};