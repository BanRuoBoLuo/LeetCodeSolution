/*******************************************************************************************
97. Interleaving String
Hard

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

*******************************************************************************************/



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        
        vector<vector<bool>> rst(s1.size()+1, vector<bool>(s2.size()+1, false));
        rst[0][0] = true;
        
        for(int i=0; i<s2.size(); i++) rst[0][i+1] = rst[0][i] && s2[i] == s3[i];
        for(int j=0; j<s1.size(); j++) rst[j+1][0] = rst[j][0] && s1[j] == s3[j];
        
        for(int j=0; j<s1.size(); j++){
            for(int i=0; i<s2.size(); i++){
                rst[j+1][i+1] = (s2[i]==s3[i+j+1] && rst[j+1][i]) || 
                    (s1[j] == s3[i+j+1] && rst[j][i+1]);
            }
        }
        return rst[s1.size()][s2.size()];
    }
};