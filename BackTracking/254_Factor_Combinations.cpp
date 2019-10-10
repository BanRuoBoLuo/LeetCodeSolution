
/******************************************************************************************
254. Factor Combinations
Medium

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.

Write a function that takes an integer n and return all possible combinations of its factors.

Note:

    You may assume that n is always positive.
    Factors should be greater than 1 and less than n.

Example 1:

Input: 1
Output: []

Example 2:

Input: 37
Output:[]

Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]

Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]

******************************************************************************************/


class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> factors = factorsOfNumber(n);
        
        vector<int> path;
        vector<vector<int>> result;
        
        traverse(n, factors, 0, path, result);
        return result;
    }
    
    
    void traverse(int n, const vector<int>& factors, size_t pos, vector<int>& path, vector<vector<int>>& result) {
        if(pos >= factors.size()) return;
        
        if(n == 1) {
            result.push_back(path);
            return;
        }
        
        for(int i=pos; i<factors.size(); ++i){
            if(n%factors[i] == 0){
                path.push_back(factors[i]);
                
                traverse(n/factors[i], factors, i, path, result);
                path.pop_back();
            }
        }
    }
    
    vector<int> factorsOfNumber(int n) {
        vector<int> result;
        
        int i=2;
        for(; i*i < n; i++){
            if(n%i == 0) {
                result.push_back(i);
                result.push_back(n/i);
            }
        }
        if(i*i==n) result.push_back(i);
        
        sort(result.begin(), result.end());
        return result;
    }
};
