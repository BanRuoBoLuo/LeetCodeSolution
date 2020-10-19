/*************************************************************************
139. Word Break
Medium

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false



*************************************************************************/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int k=1; k<=s.size(); k++) {
            for(const string& wd: wordDict) {
                int N = wd.size();
                if(k-N >= 0 && dp[k-N] 
                   && s.substr(k-N, N) == wd) dp[k] =  true;
            }
        }
        return dp[s.size()];
    }

    bool wordBreak3(string s, vector<string>& wordDict) {
        int N = s.size();
        vector<bool> dp(N+1, false);
        dp[0] = true;
        
        for(int i=0; i<N; i++) {
            if(!dp[i]) continue;
            for(const string& wd: wordDict) {
                int n = wd.size();
                if(i+n < N+1 && s.substr(i, n) == wd) dp[i+n] = true;
            }
        }
        return dp[N];
    }
    

    bool wordBreak2(string s, vector<string>& wordDict) {
        return dfs(s, 0, wordDict);
    }
    
    bool dfs(const string& s, int pos, const vector<string>& wordDict) {
        if(pos == s.size()) return true;
        
        for(const string& str: wordDict) {
            size_t sz = str.size();
            if(s.substr(pos, sz) == str && dfs(s, pos+sz, wordDict))
                return true;
        }
        
        return false;
    }
};