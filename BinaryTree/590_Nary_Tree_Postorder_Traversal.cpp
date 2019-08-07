/*************************************************************************
590. N-ary Tree Postorder Traversal
Easy

Given an n-ary tree, return the postorder traversal of its nodes' values.

*************************************************************************/

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
    vector<int> postorder(Node* root) {
        vector<int> result;
        if(root == nullptr) return result;
        
        for(Node* nd: root->children) {
            vector<int> child = postorder(nd);
            result.insert(result.end(), child.begin(), child.end());
        }
        result.push_back(root->val);
        return result;
    }
};