/******************************************************************************************
743. Network Delay Time
Easy

There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:

    N will be in the range [1, 100].
    K will be in the range [1, N].
    The length of times will be in the range [1, 6000].
    All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.

*******************************************************************************************/
class Solution {
public:

	//Bellman Ford Algorithm
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                if (dist[e[0]] != INT_MAX) {
                    dist[e[1]] = min(dist[e[1]], dist[e[0]] + e[2]);
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++){
            if(dist[i] == INT_MAX ) return -1;
            maxwait = max(maxwait, dist[i]);
        }
        return maxwait;
    }
};