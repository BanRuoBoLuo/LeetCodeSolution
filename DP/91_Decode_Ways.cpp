/******************************************************************************************
91. Decode Ways
Medium

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

******************************************************************************************/

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0') return 0;
        
        vector<int>dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=1; i<s.size(); i++) {
            if(s[i] != '0') dp[i+1] += dp[i];
            if(s[i-1] != '0' && stoi(s.substr(i-1, 2))<=26) dp[i+1] += dp[i-1];
            
            if(dp[i+1] == 0) return 0;
        }
        return dp[s.size()];
    }
};