/*******************************************************************************************
59. Spiral Matrix II
Medium

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*******************************************************************************************/



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> rst(n, vector<int> (n, 0));
        
        int lft = 0, rgt = n-1; 
        int idx = 1;
        while(lft < rgt) {
            for(int i=lft; i<rgt; i++) rst[lft][i] = idx++;
            for(int j=lft; j<rgt; j++) rst[j][rgt] = idx++;
    
            for(int i=rgt; i>lft; i--) rst[rgt][i] = idx++;
            for(int j=rgt; j>lft; j--) rst[j][lft] = idx++;
            
            lft ++; rgt --;
        }
        
        if(lft == rgt) rst[lft][rgt] = idx;
        return rst;
    }
};