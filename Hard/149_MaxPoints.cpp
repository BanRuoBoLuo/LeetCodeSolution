
/******************************************************************************************

149. Max Points on a Line
Hard

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
******************************************************************************************/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() <= 2) return points.size();
            
        int maxLines=0;
        for(int i=0; i<points.size(); i++){
            int x0 = points[i].x, y0 = points[i].y;
            
            unordered_map<double, int> lineCount;
            int samePoint = 1;
            
            for(int j=i+1; j<points.size(); j++){                
                if(x0 == points[j].x) {
                    if(y0 == points[j].y) samePoint ++;
                    else lineCount[std::numeric_limits<double>::infinity()] ++;
                }
                else {
                    double slope = 1.0*(y0-points[j].y)/(x0-points[j].x);
                    lineCount[slope] ++;
                }
            }
            
            maxLines = max(maxLines, samePoint);
            for (auto it = lineCount.begin(); it != lineCount.end(); ++it){
                maxLines = max(it->second + samePoint, maxLines);
            }
        }
        
        return maxLines;   
    }
    
};