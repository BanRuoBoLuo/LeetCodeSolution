/*******************************************************************************************
969. Pancake Sorting
Medium

Given an array A, we can perform a pancake flip: 
We choose some positive integer k <= A.length, 
then reverse the order of the first k elements of A.  
We want to perform zero or more pancake flips 
(doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  
Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
*******************************************************************************************/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        
        vector<int> res;
        int len = A.size();

        while(len > 1) {
            auto it = max_element(A.begin(), A.begin()+len);
            if(it == A.begin()+len-1){len --;}
            else {
                if(it != A.begin()) {
                    res.push_back(it - A.begin()+1);
                    reverse(A.begin(), it+1);
                }
                
                res.push_back(len);
                reverse(A.begin(), A.begin()+len);
                
                len --;
            }
        }
        return res;
    }
};