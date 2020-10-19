/*******************************************************************************************
30. Substring with Concatenation of All Words
Hard

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

 

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []

*******************************************************************************************/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty()) return result;
        
        int n = words.size(), m = words[0].size();
        if(s.size() < m*n) return result;
        
        unordered_map<string, int> count;
        for(const string& str: words) {
            count[str] ++;
        }
        
        for(int i=0; i + m*n <= s.size(); i++) {
             unordered_map<string, int> unused(count);
            
            for(int j=0; j<n; j++) {
                string nxt = s.substr(i+j*m, m);
                auto it = unused.find(nxt);
                if( it == unused.end() || it->second == 0) break;
                if(--it->second == 0) unused.erase(it);
            }
            
            if(unused.empty()) result.push_back(i);
        }
        return result;
        
    }
};