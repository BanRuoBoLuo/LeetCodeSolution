/******************************************************************************************
890. Find and Replace Pattern
Medium

You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.

 

Note:

    1 <= words.length <= 50
    1 <= pattern.length = words[i].length <= 20

******************************************************************************************/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> rst;
        for(const string& str: words) {
            if(matchPattern(str, pattern)) rst.push_back(str);
        }
        return rst;
    }
    
    bool matchPattern(const string& word, const string& pattern){
        if(word.size() != pattern.size()) return false;
        
        unordered_map<char, char> wp;
        unordered_map<char, char> pw;
        
        for(int i=0; i<word.size(); i++){
            auto pit = pw.find(pattern[i]);
            auto wit = wp.find(word[i]);
            
            if(pit != pw.end() && wit != wp.end()){
                if(pit->second != word[i] || wit->second != pattern[i]) return false;
            } else if(wit == wp.end() && pit == pw.end()) {
                wp[word[i]] = pattern[i];
                pw[pattern[i]] = word[i];
            } else {
                return false;
            }
        }
        return true;
    }
};