/*******************************************************************************************
383. Ransom Note
Easy

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*******************************************************************************************/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.empty()) return true;
        
         vector<int> notes(26, 0);
        for(char c: ransomNote) {
            notes[c-'a'] ++;
        }
        
        int cnt = 0;
        for(int i=0; i< 26; i++) {
            if(notes[i] == 0) cnt ++;
        }
        
        for(char c: magazine) {
            if(notes[c-'a'] != 0) {
                notes[c-'a']  -- ;
                if(notes[c-'a'] == 0) cnt ++;
            }
            if(cnt == 26) return true;
        }
        return false;
    }
};