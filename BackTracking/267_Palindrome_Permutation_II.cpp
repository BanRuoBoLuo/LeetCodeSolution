/*******************************************************************************************
267. Palindrome Permutation II
Medium

Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]

Example 2:

Input: "abc"
Output: []
*******************************************************************************************/



class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> cnt;
        
        for(char c: s) {
            cnt[c] ++;
        }
        
        string oddChar = "";
        int oddCnt = 0;
        for(auto it = cnt.begin(); it != cnt.end(); ++it) {
            if(it->second % 2 != 0) {
                oddChar = string(1, it->first);
                oddCnt ++;
            }
            
            it->second /= 2;
            if(oddCnt > 1) return vector<string> {};
        }
        
        string path;
        unordered_set<string> perms;
        permutations(cnt, s.size()/2, path, perms);
        
        vector<string> rst;
        for(string str: perms) {
            string rev = str;
            reverse(rev.begin(), rev.end());
            rst.push_back(str + oddChar + rev);
        }
        
        return rst;
        
    }
    
    typedef unordered_map<char, int>::iterator mit;
    
    void permutations(unordered_map<char, int>& cnt, size_t N, string& path, unordered_set<string> &perms) {
        if(path.size() == N) {
            perms.insert(path);
            return;
        }
        
        for(auto it=cnt.begin(); it != cnt.end(); ++it) {
            if(it->second > 0) {
                path.push_back(it->first);
                it->second --;
                
                permutations(cnt, N, path, perms);
                
                it->second++;
                path.pop_back();
            }
        }
    }
};