/*******************************************************************************************
1198. Find Smallest Common Element in All Rows
Medium

Given a matrix mat where every row is sorted in increasing order, return the smallest common element in all rows.

If there is no common element, return -1.

 

Example 1:

Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5

 

Constraints:

    1 <= mat.length, mat[i].length <= 500
    1 <= mat[i][j] <= 10^4
    mat[i] is sorted in increasing order.

*******************************************************************************************/




class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int total = 0;
        int M = mat.size();
        using E = vector<int>;
        priority_queue<E, vector<E>, std::greater<E>> nums;
        
        for(int i=0; i < M; i++){
            if(mat[i].empty()) return -1;
            nums.push({mat[i][0], i, 0});
            total += mat[i][0];
        }
        
        vector<int> top = nums.top();
        while(top[0] * M != total && top[2] < mat[top[1]].size()-1) {
            int i = top[1], j = top[2];
            nums.pop();
            nums.push({mat[i][j+1], i, j+1});
            total += mat[i][j+1] - top[0];
            top = nums.top();
        }
        if(top[0] * M == total) return top[0];
        return -1;
    }
};


class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int total = 0;
        int M = mat.size();
        using E = std::tuple<int, int, int>;
        priority_queue<E, vector<E>, std::greater<E>> nums;
        
        for(int i=0; i < M; i++){
            if(mat[i].empty()) return -1;
            nums.push({mat[i][0], i, 0});
            total += mat[i][0];
        }
        
        E top = nums.top();
        int n = std::get<0>(top), i = std::get<1>(top), j = std::get<2>(top);
        while(n * M != total && j < mat[i].size()-1) {
            nums.pop();
            nums.push({mat[i][j+1], i, j+1});
            total += mat[i][j+1] - n;
            top = nums.top();
            n = std::get<0>(top); i = std::get<1>(top); j = std::get<2>(top);

        }
        if(n * M == total) return n;
        return -1;
    }
};