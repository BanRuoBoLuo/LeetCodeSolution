/******************************************************************************************
332. Reconstruct Itinerary
Medium

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

    If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    All airports are represented by three capital letters (IATA code).
    You may assume all tickets form at least one valid itinerary.
*******************************************************************************************/

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, vector<string>> trip;
        
        for(const auto& x : tickets) {
            trip[x.first].push_back(x.second);
        }
        
        for(auto it = trip.begin(); it!=trip.end(); ++it) {
            sort(it->second.begin(), it->second.end());
        }
        
        vector<string> path{"JFK"};
        vector<string> rst;
        bool finished = false;
        dfs(trip, rst, path, "JFK", tickets.size(), finished);
        
        return rst;
    }
    
    void dfs(unordered_map<string, vector<string>>& trip, vector<string> & rst, vector<string>& path, string from, int length, bool& finished) {

        if(path.size() == length+1) {
            finished = true;
            rst=path;
            return;
        }
                
        for(int i=0; i<trip[from].size() && !finished; i++) {
            string dest = trip[from][i];
            path.push_back(dest);
            trip[from].erase(trip[from].begin()+i);
            dfs(trip, rst, path, dest, length, finished);
            
            trip[from].insert(trip[from].begin()+i, dest);
            path.pop_back();
        }
    }

    //***Get all possible paths
    void dfs_all(unordered_map<string, vector<string>>& trip, vector<vector<string>> & rst, vector<string>& path, string from, int length) {

        if(path.size() == length+1) {
            rst.push_back(path);
            return;
        }
                
        for(int i=0; i<trip[from].size() && !finished; i++) {
            string dest = trip[from][i];
            path.push_back(dest);
            trip[from].erase(trip[from].begin()+i);
            dfs(trip, rst, path, dest, length, finished);
            
            trip[from].insert(trip[from].begin()+i, dest);
            path.pop_back();
        }
    }
};