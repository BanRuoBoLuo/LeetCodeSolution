/******************************************************************************************
812. Largest Triangle Area
Easy

You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.

Notes:

    3 <= points.length <= 50.
    No points will be duplicated.
     -50 <= points[i][j] <= 50.
    Answers within 10^-6 of the true value will be accepted as correct.


Heron's formula states that the area of a triangle whose sides have lengths a, b, and c is

    A = sqrt{s(s-a)(s-b)(s-c)}
where s is the semi-perimeter of the triangle; that is,

    s = (a+b+c)/2
******************************************************************************************/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double a = 0.0, b = 0.0, c = 0.0;
        double s = 0.0, A = 0.0, maxA = 0.0;
        for(int i=0; i<points.size()-2 ; ++i)
            for(int j=i+1; j<points.size()-1; ++j)
                for(int k=j+1; k<points.size(); ++k) {
                    
                    a = sqrt(pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2));
                    b = sqrt(pow(points[k][0]-points[i][0],2)+pow(points[k][1]-points[i][1],2));
                    c = sqrt(pow(points[k][0]-points[j][0],2)+pow(points[k][1]-points[j][1],2));
                    
                    s = (a+b+c)/2;
                    A =sqrt(s * (s-a) * (s-b) * (s-c));
                    
                    maxA = max(maxA, A);
                }  
        return maxA;
    }
};