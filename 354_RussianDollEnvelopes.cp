/******************************************************************************************
354. Russian Doll Envelopes
Hard

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.
*******************************************************************************************/

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        //Sort envelopes, then it is the LIS problem
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b){return a.first==b.first? a.second>b.second : a.first < b.first;});
        
        vector<int> heights;
        size_t maxLen = 0;
        
        for(auto x : envelopes) {
            auto it = lower_bound(heights.begin(), heights.end(), x.second);
            if (it == heights.end()) {
                heights.push_back(x.second);
                maxLen = max(maxLen, heights.size());
            }
            else {
                *it = x.second;
            }
        }
        return maxLen;        
    }
};