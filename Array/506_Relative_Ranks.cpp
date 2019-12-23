/*******************************************************************************************
506. Relative Ranks
Easy

Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:

Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.

Note:

    N is a positive integer and won't exceed 10,000.
    All the scores of athletes are guaranteed to be unique.

*******************************************************************************************/


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int N = nums.size();
        vector<pair<int, int>> idx(N);
        
        for(int i=0; i<N; i++){
            idx[i] = make_pair(nums[i], i);
        }
        
        sort(idx.begin(), idx.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        });
        
        vector<string> rst(N);
        if(N > 0) rst[idx[0].second] = "Gold Medal";
        if(N > 1) rst[idx[1].second] = "Silver Medal";
        if(N > 2) rst[idx[2].second] = "Bronze Medal";
        
        
        for(int i=3; i<idx.size(); i++) {
            rst[idx[i].second] = to_string(i+1);
        }
        return rst;
    }
};