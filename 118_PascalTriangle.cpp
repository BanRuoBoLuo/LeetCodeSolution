/******************************************************************************************

118. Pascal's Triangle
Easy

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.
******************************************************************************************/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for(int r = 1; r<=numRows; r++){
            vector<int> row(r, 1);
            
            for(int i=1; i<r-1; i++) {
                row[i] = result.back().at(i-1) + result.back().at(i);
            }
            
            result.push_back(row);
        }
        return result;
    }

    vector<int> getKthRow(int K) {
        vector<int> result(K+1, 1);
        
        for(int row=2; row<=K; row++) {
            for(int i=row-1; i>0; i--) {
                result[i] = result[i] + result[i-1];
            }
        }
        return result;
    }
};