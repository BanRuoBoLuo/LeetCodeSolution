/***************************************************************************************
214. Shortest Palindrome
Hard

Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"

******************************************************************************************/


class Solution {
public:
    string shortestPalindrome(string s) {
        
        size_t N = s.size();

        string sr = s;
        reverse(sr.begin(), sr.end());
        
        for(int len=s.size(); len>0; len--) 
        {
            if(sr.substr(N-len) == s.substr(0, len)) 
                return sr.substr(0, N-len) + s;
        }
        return sr+s;
    }

    string shortestPalindrome2(string s) {
        
        size_t N = s.size();
        if(N < 2) return s;
        
        vector<vector<bool>> dp(N, vector<bool> (N, false));
        
        for(int i=0; i<N;  i++) dp[i][i] = true;
        for(int i=0; i<N-1;i++) dp[i][i+1] = s[i]==s[i+1];
        
        for(int i=N-3; i>=0; i--) {
            for(int j=i+2; j<N; j++) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
        
        if(dp[0][N-1]) return s;
        
        int pos = N-1;
        while(pos>0 && !dp[0][pos]) pos--;
        
        string str = s.substr(pos+1);
        reverse(str.begin(), str.end());
        
        return str + s;
    }

}