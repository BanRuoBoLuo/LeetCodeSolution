/*******************************************************************************************
47. Permutations II
Medium

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*******************************************************************************************/


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int x: nums) {
            count[x] ++;
        }
        
        vector<int> p;
        vector<vector<int>> result;
        
        traverse(count, nums.size(), p, result);
        return result;
    }
    
    
    void traverse(unordered_map<int, int>& count, int N, vector<int>& p, vector<vector<int>>& result) {
        if(p.size() == N) {
            result.push_back(p);
            return;
        }
        
        for(auto it = count.begin(); it != count.end(); ++it) {
            if (it->second > 0) {
                p.push_back(it->first);
                it->second --;
                traverse(count, N, p, result);
                it->second ++;
                p.pop_back();
            }
        }
    }
};