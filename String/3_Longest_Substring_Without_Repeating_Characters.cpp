/***********************************************************************
3. Longest Substring Without Repeating Characters
Medium

7784

458

Add to List

Share
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

***********************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        if(s.empty()) return 0;
        
        unordered_map<char, int> idx;
        
        int len = 0; 
        int start = 0;

        for(int i=0; i<s.size(); i++) {
            if(idx.find(s[i]) != idx.end() && idx[s[i]] >= start) {
                len = max(len, i-start);
                start = idx[s[i]]+1;
            }
            idx[s[i]] = i;
        }
        
        return max(len, (int)s.size()-start);
    }

    int lengthOfLongestSubstring2(const string& s) {
        if(s.size() < 2) return s.size();
        
        int result = 1;
        vector<int> length(s.size(), 1);
        
        unordered_map<char, int> prev;
        prev[s[0]] = 0;
        for(int i=1; i<s.size(); i++) {
            if(prev.count(s[i]) == 0 || prev[s[i]] < i- length[i-1]) {
                length[i] = length[i-1] + 1;
            } else {
                length[i] = i - prev[s[i]];
            }
            
            prev[s[i]] = i;
            result = max(result, length[i]);
        }
        
        return result;
    }


    int lengthOfLongestSubstring2(string s) {
        int maxLen = 0;
        
        int left = -1;
        unordered_map<char, int> pos;
        for(int i=0; i<s.size(); i++){
            if(pos.find(s[i]) != pos.end() && pos[s[i]] > left){
                left = pos[s[i]];
            }
            pos[s[i]] = i;
            maxLen = max(maxLen, i-left);
        }
        return maxLen;
    }
};