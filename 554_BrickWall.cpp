/******************************************************************************************

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. 
The bricks have the same height but different width. 
You want to draw a vertical line from the top to the bottom and cross the least bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing 
the width of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. 
You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

You cannot draw a line just along one of the two vertical edges of the wall, in which case 
the line will obviously cross no bricks. 


Thought:
	The idea is to get the max count that brick edges end at some width

*******************************************************************************************/


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> cnt;
        
        for(auto& v : wall) {
            int cut = 0;
            for(int i=0; i<v.size()-1; i++) { //ignore the last, as it comes to edge
                cut += v[i];
                cnt[cut] ++;
            }
        }
        
        int maxCut = 0;
        for(auto it = cnt.begin(); it != cnt.end(); ++it) {
            maxCut = max(maxCut, it->second);
        }
        
        return wall.size()-maxCut;
    }
};