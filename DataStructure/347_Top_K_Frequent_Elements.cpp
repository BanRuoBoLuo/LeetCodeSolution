/***********************************************************************
347. Top K Frequent Elements
Medium

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


**********************************************************************/



class Solution {
public:
    typedef pair<int, int> F;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int x: nums) cnt[x] ++;
        
        priority_queue<F, vector<F>, std::greater<F>> frequent;
        for(auto it = cnt.begin(); it != cnt.end(); ++it) {
            if(frequent.size() < k) {
                frequent.push(make_pair(it->second, it->first));
            } else if (frequent.top().first < it->second) {
                frequent.pop();
                frequent.push(make_pair(it->second, it->first));
            }
        }
        
        vector<int> rst;
        while(!frequent.empty()) {
            rst.push_back(frequent.top().second);
            frequent.pop();
        }
        
        return rst;
    }
};