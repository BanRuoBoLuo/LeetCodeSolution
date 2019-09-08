/******************************************************************************************
118. Pascal's Triangle
Easy

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

******************************************************************************************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for(int k=1; k<=numRows; k++){
            vector<int> level(k, 1);
            for(int j=1; j<k-1; j++){
                level[j] = result[k-2][j]+result[k-2][j-1];
            }
            result.push_back(level);
        }
        return result;
    }
};