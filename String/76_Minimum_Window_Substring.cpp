/*******************************************************************************************
76. Minimum Window Substring
Hard

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note:

    If there is no such window in S that covers all characters in T, return the empty string "".
    If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

*******************************************************************************************/



class Solution {
public:
    string minWindow(string S, string T) {
        const int ASCII_MAX = 256;
        vector<int> expected(ASCII_MAX, 0);
        vector<int> appeared(ASCII_MAX, 0);
        int count = 0;
        
        for(unsigned char c: T) expected[c] ++;
        string rst = S+S;
        
        int bgn = 0;
        for(int i=0; i < S.size(); i++) {
            int idx = S[i];
            if(expected[idx] > 0) {
                if (appeared[idx] < expected[idx]) count ++;
                appeared[idx] ++;
            }
            
            if(count == T.size()) {
               
                while(expected[S[bgn]] == 0 || appeared[S[bgn]] > expected[S[bgn]] ) {
                    if(expected[S[bgn]] > 0) appeared[S[bgn]] --;
                    bgn ++;
                }
                if (i-bgn+1 < rst.size()) {
                    rst = S.substr(bgn, i-bgn+1);
                }
                
                appeared[S[bgn]] --;
                bgn ++;
                count --;
            }
        }
        if(rst.size() > S.size()) return "";
        return rst;
    }
};