/*******************************************************************************************
821. Shortest Distance to a Character
Easy

Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
*******************************************************************************************/

 
 class Solution {
public:
    vector<int> shortestToChar(string S, char c) {
        vector<int> result(S.size(), INT_MAX);
        
        int pos = -1;
        for(int i=0; i<S.size(); i++){
            if(S[i] == c) pos = i;
            if(pos!=-1)result[i] = i-pos;
        }
        
        pos = -1;
        for(int i=S.size()-1; i>=0; i--){
            if(S[i] == c) pos = i;
            if(pos!=-1)result[i] = min(pos-i, result[i]);
        }
        return result;
    }
};