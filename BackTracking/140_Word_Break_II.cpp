/*************************************************************************

140. Word Break II
Hard

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]

*************************************************************************/


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        int N = s.size();
        vector<vector<string>> dp(N+1);
        
        dp[0] = vector<string> {""};
        for(int i=1; i<=N; i++) {
            
            for(const string& wd: wordDict) {
                int n = wd.size();
                if (i-n>=0 && s.substr(i-n, n) == wd && !dp[i-n].empty()) {
                    for (const string& str: dp[i-n] ) {
                        dp[i].push_back(str + wd + " ");
                    }
                }
            }
        }
        
        for(string& str: dp[N]) {
            if(str.size() > 1) str.pop_back();
        }
        return dp[N];
    }
    
    vector<string> wordBreak2(string s, vector<string>& wordDict) {
        vector<string> path;
        vector<string> result;
        
        traverse(s, 0, wordDict, path, result);
        return result;
    }
    
    void traverse(const string& s, int pos, const vector<string>& wordDict, vector<string> &path, vector<string> &result) {
        if(pos == s.size()) {
            string rst;
            for(const string& str: path) {
                rst += str + " ";
            }
            rst.pop_back();
            result.push_back(rst);
            return;
        }
        
        if(pos > s.size()) return;
        
        for(const string& wd: wordDict) {
            int N = wd.size();
            if(pos+N <= s.size() && s.substr(pos, N) == wd) {
                path.push_back(wd);
                traverse(s, pos+N, wordDict, path, result);
                path.pop_back();
            }
        }
    }
};