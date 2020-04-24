/*******************************************************************************************
127. Word Ladder
Medium

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*******************************************************************************************/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(beginWord); 
        visited.insert(beginWord);
        
        int level = 1;
        bool found = false;
        while(!q.empty() && !found) {
            level ++;
            
            queue<string> nextLevel;
            while(!q.empty() && !found) {
                
                string next = q.front(); q.pop();
                for(const string& str: transformation(next, dict, visited)) {
                    if(str == endWord) {
                        found = true; break;
                    } else {
                        nextLevel.push(str);
                    }
                }
            }
            q = nextLevel;
        }
        return found? level: 0;
    }
    
    vector<string> transformation(string word, const unordered_set<string>& dict, unordered_set<string>& visited) {
        vector<string> rst;
        for(int i=0; i<word.size(); i++) {
            char w = word[i];
            for(char c = 'a'; c <= 'z'; ++c) {
                if(c == w) continue;
                
                word[i] = c;
                if(dict.count(word)> 0 && visited.count(word) == 0) {
                    rst.push_back(word);
                    visited.insert(word);
                }
            }
            word[i] = w;
        }
        return rst;
    }
    
};