/*******************************************************************************************
255. Verify Preorder Sequence in Binary Search Tree
Medium

Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree: 

     5
    / \
   2   6
  / \
 1   3

Example 1:

Input: [5,2,6,1,3]
Output: false

Example 2:

Input: [5,2,1,3,6]
Output: true


*******************************************************************************************/
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return verifyPreorderHelper(preorder.begin(), preorder.end());
    }
    
    bool verifyPreorderHelper(vector<int>::iterator lft, vector<int>::iterator rgt) {
        if(distance(lft, rgt) < 2) return true;
        
        int pivot = *lft;
        
        auto it = lft+1;
        while(it != rgt && *it < pivot) ++it;
        
        for(auto ii = it; ii != rgt; ii++) {
            if(*ii < pivot) return false;
        }
        
        return verifyPreorderHelper(lft+1, it) && verifyPreorderHelper(it, rgt);
    }
};