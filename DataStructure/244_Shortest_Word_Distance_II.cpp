/******************************************************************************************
244. Shortest Word Distance II
Medium

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3

Input: word1 = "makes", word2 = "coding"
Output: 1

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

*******************************************************************************************/


class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i=0; i<words.size(); ++i){
            pos[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> pos1 = pos[word1];
        vector<int> pos2 = pos[word2];
        
        if(pos1.empty() || pos2.empty()) return -1;
        int idx1 = 0, idx2 = 0;
        int result = INT_MAX;
        while(idx1<pos1.size() && idx2<pos2.size()){
            if(pos1[idx1] < pos2[idx2]) {
                result = min(result, pos2[idx2]-pos1[idx1]);
                idx1++;
            } else {
                result = min(result, pos1[idx1]-pos2[idx2]);
                idx2++;
            }
        }
        return result;
    }
    
    unordered_map<string, vector<int>> pos;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */