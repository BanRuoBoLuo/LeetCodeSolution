/******************************************************************************************

703. Kth Largest Element in a Stream
Easy

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

*******************************************************************************************/

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        size = k;
        for(int x : nums) add(x);
    }
    
    int add(int val) {
        if(maxHeap.size() < size) maxHeap.push(val);
        else if(maxHeap.top() < val) {maxHeap.pop(); maxHeap.push(val);}
        
        return maxHeap.top();
    }
    
    priority_queue<int, vector<int>, std::greater<int> > maxHeap;
    int size;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */