/******************************************************************************************
1128. Number of Equivalent Domino Pairs
Easy

Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

 

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

 

Constraints:

    1 <= dominoes.length <= 40000
    1 <= dominoes[i][j] <= 9

******************************************************************************************/


class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> equiv;
        
        for(auto& v: dominoes){
            if(v[0] > v[1]) swap(v[0], v[1]);
            pair <int,int> a = {v[0], v[1]};
            if(equiv.find(a) == equiv.end()) {
                equiv[a] = 1;
            } else {
                equiv[a] ++;
            }
        }
        
        int result = 0;
        for(auto it = equiv.begin(); it != equiv.end(); ++it) {
            result += it->second *(it->second-1)/2;
        }
        return result;
    }

};