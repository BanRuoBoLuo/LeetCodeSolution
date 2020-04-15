/*******************************************************************************************
316. Remove Duplicate Letters
Hard

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: "bcabc"
Output: "abc"

Example 2:

Input: "cbacdcbc"
Output: "acdb"

*******************************************************************************************/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        unordered_map<char, int> cnt;
        for(char c : s) cnt[c] ++;
        
        string rst;
        for(char c: s) {
            cnt[c] --;
            if(rst.find(c) != string::npos) {
                continue;
            } else {
                while(!rst.empty() && rst.back() > c && 
                     cnt[rst.back()] > 0) {
                    rst.pop_back();
                }
                rst.push_back(c);
            }
        }
        return rst;
    }
};