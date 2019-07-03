/******************************************************************************************
133. Clone Graph
Medium

Given the head of a graph, return a deep copy (clone) of the graph. Each node in the graph contains a label (int) and a list (List[UndirectedGraphNode]) of its neighbors. There is an edge between the given node and each of the nodes in its neighbors.

******************************************************************************************/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {        
        unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> clones;
        
        cloneGraphDFS(node, clones);
        return clones[node];       
    }
    
    UndirectedGraphNode* cloneGraphDFS(UndirectedGraphNode *node, unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*>& clones) {
        if(node == nullptr) return nullptr;
        
        if(clones.find(node) != clones.end()) 
            return clones[node];
        
        UndirectedGraphNode * nd = new UndirectedGraphNode(node->label);
        clones[node] = nd;
        
        for(auto n : node->neighbors) {
            clones[node]->neighbors.push_back(cloneGraphDFS(n, clones));
        }
        return nd;
    }
    
    UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {   
        if(node==nullptr) return nullptr;
        
        unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> clones;
        queue<UndirectedGraphNode*> q;
        
        q.push(node);
        clones[node] = new UndirectedGraphNode(node->label);
        
        while(!q.empty()){
            UndirectedGraphNode* curr = q.front(); q.pop();
            
            for(auto nbr : curr->neighbors){
                if(clones.find(nbr)==clones.end()) {
                    clones[nbr] = new UndirectedGraphNode(nbr->label);;
                    q.push(nbr);
                }
                clones[curr]->neighbors.push_back(clones[nbr]);
            }
        }
        return clones[node];
    }

};