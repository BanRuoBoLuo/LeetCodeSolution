/*************************************************************
49. Group Anagrams
Medium

2560

148

Add to List

Share
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

*************************************************************/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> group;
        
        for(const string& str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            
            group[s].push_back(str);
        }
        
        vector<vector<string>> result;
        for(auto it = group.begin(); it != group.end(); ++it) {
            result.push_back(it->second);
        }
        
        return result;
     }
};


