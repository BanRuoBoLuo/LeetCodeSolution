/******************************************************************************************
1232. Check If It Is a Straight Line
Easy

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.


Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

 

Constraints:

    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.

/******************************************************************************************

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        auto it = unique(coordinates.begin(), coordinates.end());
        coordinates.erase(it, coordinates.end());
        
        if(coordinates.size() < 3) return true;
        
       int x1 = coordinates[0][0], y1 = coordinates[0][1];
       int x2 = coordinates[1][0], y2 = coordinates[1][1];
        
        for(int i=2; i<coordinates.size(); i++) {
            if((coordinates[i][1]-y1)*(x2-x1) != (y2-y1)*(coordinates[i][0]-x1)) return false;
        }
        
        return true;
    }
};