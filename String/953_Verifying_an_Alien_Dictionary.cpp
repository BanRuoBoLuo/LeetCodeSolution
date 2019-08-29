/*********************************************************************************************
953. Verifying an Alien Dictionary
Easy

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

*********************************************************************************************/
 

 class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> letters;
        for(int i=0; i<order.size(); i++) letters[order[i]] = i;
        
        for(int i=0; i<words.size()-1; i++){
            if(!lexicographicalOrder(words[i], words[i+1], letters)) return false;
        }
        return true;
    }
    
    bool lexicographicalOrder(const string& word1, const string& word2, unordered_map<char, int>& letters) {
        
        for(int i=0; i<word1.size() && i < word2.size(); i++) {
            if(letters[word1[i]] < letters[word2[i]]) return true;
            else if (letters[word1[i]] > letters[word2[i]]) return false;
        }
        return word1.size() < word2.size();
    }
};