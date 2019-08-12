/*******************************************************************************************
429. N-ary Tree Level Order Traversal
Easy

Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Note:

    The depth of the tree is at most 1000.
    The total number of nodes is at most 5000.

*******************************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> result;
        if(root==nullptr) return result;
        
        Node* nd = nullptr;
        queue<Node*> levels;
        levels.push(root);
        
        while(!levels.empty()){
            vector<int> nexeLevel;
            int N = levels.size();
            for(int i=0; i<N; i++){
                nd = levels.front(); levels.pop();
                nexeLevel.push_back(nd->val);
                for(Node* child: nd->children) levels.push(child);
            }
            result.push_back(nexeLevel);
        }
        return result;

    }
};