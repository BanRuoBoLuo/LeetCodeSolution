/*******************************************************************************************
589. N-ary Tree Preorder Traversal
Easy

Given an n-ary tree, return the preorder traversal of its nodes' values.
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
    vector<int> preorder2(Node* root) {
        
        vector<int> result;
        if(root==nullptr) return result;
        
        result.push_back(root->val);
        for(Node* child: root->children) {
            vector<int> rst = preorder(child);
            result.insert(result.end(), rst.begin(), rst.end());
        }
        return result;
    }
    
    
    vector<int> preorder(Node* root) {
        if(root == nullptr) return vector<int> {};
        
        vector<int> result;
        stack<Node*> nodes;
        
        while(root!=nullptr || !nodes.empty()) {
            if(root==nullptr) {
                root=nodes.top(); 
                nodes.pop();
            } else {
                result.push_back(root->val);
                
                if(root->children.size() > 0) {
                    for(int i=root->children.size()-1; i>0; i--) nodes.push(root->children[i]);
                    root = root->children[0];
                }
                else 
                    root = nullptr;
            }
        }
        return result;
    }
};