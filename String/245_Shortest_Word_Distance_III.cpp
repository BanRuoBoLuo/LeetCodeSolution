/*******************************************************************************************
245. Shortest Word Distance III
Medium

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1

Input: word1 = "makes", word2 = "makes"
Output: 3

Note:
You may assume word1 and word2 are both in the list.


*******************************************************************************************/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx1 = -words.size(), idx2 = idx1;
        
        int result = words.size();
        for(int i=0; i<words.size(); ++i){
            if(word1==word2){
                if(words[i] == word1){
                    result = min(i-idx1, result);
                    idx1 = i;
                }
            }
            else {
                if(words[i] == word1){
                    result = min(result, i-idx2);
                    idx1 = i;
                } else if (words[i] == word2) {
                    result = min(result, i-idx1);
                    idx2 = i;
                }
            }
        }
        return result;
    }
};