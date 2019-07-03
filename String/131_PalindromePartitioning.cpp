/******************************************************************************************
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
******************************************************************************************/

class Solution {
public:
    vector<vector<string>> partition(const string& s) {
        
        size_t N = s.size();
        vector<vector<bool>> dp(N, vector<bool> (N, false));
        for(int i=N-1; i>=0; i--) {
            for(int j=i; j<N; j++) dp[i][j] = (j-i < 2 || dp[i+1][j-1]) && s[i]==s[j];
        }
        
        vector<string> path;
        vector<vector<string>> result;
        
        dfs(result, path, s, 0, dp);
        return result;
    }
    
    void dfs(vector<vector<string>>& result, vector<string>& path, const string& s, int pos, const vector<vector<bool>>& dp) {
        if(pos == s.size()) {
            result.push_back(path);
            return;
        }
        
        for(int i=pos; i<s.size(); i++) {
            if(dp[pos][i]) {
                cout << "dp["<<pos<<"][" << i << "]" << endl;
                path.push_back(s.substr(pos, i-pos+1));
                dfs(result, path, s, i+1, dp);
                
                path.pop_back();
            }
        }
        
    }
}; 