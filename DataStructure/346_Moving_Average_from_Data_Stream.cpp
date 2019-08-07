/*******************************************************************************************
346. Moving Average from Data Stream
Easy

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

*******************************************************************************************/


class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        windowSize = size;
        avg = 0.0;
    }
    
    double next(int val) {
        int N = nums.size() ;
        if(N < windowSize) {
            avg =  (N * avg + val)/(N+1);
        }
        else {
            avg =  (windowSize*avg - nums.front() + val)/windowSize;
            nums.pop();
        }
        nums.push(val);
        return avg;
    }
    
    int windowSize;
    double avg;
    std::queue<int> nums;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */