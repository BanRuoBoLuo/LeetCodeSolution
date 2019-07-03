/******************************************************************************************

558. Quad Tree Intersection
Easy

A quadtree is a tree data in which each internal node has exactly four children: topLeft, topRight, 
bottomLeft and bottomRight. Quad trees are often used to partition a two-dimensional space 
by recursively subdividing it into four quadrants or regions.

We want to store True/False information in our quad tree. The quad tree is used to represent 
a N * N boolean grid. For each node, it will be subdivided into four children nodes until the 
values in the region it represents are all the same. 

Each node has another two boolean attributes : isLeaf and val. 
isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node 
contains the value of the region it represents.

Your task is to implement a function that will take two quadtrees and return a quadtree that represents the logical OR (or union) of the two trees.

A:                 B:                 C (A or B):
+-------+-------+  +-------+---+---+  +-------+-------+
|       |       |  |       | F | F |  |       |       |
|   T   |   T   |  |   T   +---+---+  |   T   |   T   |
|       |       |  |       | T | T |  |       |       |
+-------+-------+  +-------+---+---+  +-------+-------+
|       |       |  |       |       |  |       |       |
|   F   |   F   |  |   T   |   F   |  |   T   |   F   |
|       |       |  |       |       |  |       |       |
+-------+-------+  +-------+-------+  +-------+-------+

Note:

    Both A and B represent grids of size N * N.
    N is guaranteed to be a power of 2.
    If you want to know more about the quad tree, you can refer to its wiki.
    The logic OR operation is defined as this: "A or B" is true if A is true, or if B is true, 
    or if both A and B are true.

*******************************************************************************************/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* qt1, Node* qt2) {
        if(!qt1) return qt2;
        if(!qt2) return qt1;
        
        if(qt1->isLeaf){
            return qt1->val? qt1: qt2;
        }
        
        if(qt2->isLeaf) {
            return qt2->val? qt2: qt1;
        }
    
        Node* tl = intersect(qt1->topLeft, qt2->topLeft);
        Node* tr = intersect(qt1->topRight, qt2->topRight);
        Node* bl = intersect(qt1->bottomLeft, qt2->bottomLeft);
        Node* br = intersect(qt1->bottomRight, qt2->bottomRight);
        
        if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val == tr->val && tr->val == bl->val && bl->val == br->val)
            return new Node(tl->val, true, nullptr, nullptr, nullptr, nullptr);
        
        return new Node(false, false, tl, tr, bl, br);
    }
};