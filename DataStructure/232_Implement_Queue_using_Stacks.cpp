/*************************************************************************
232. Implement Queue using Stacks
Easy

Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

Notes:

    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), 
    as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

*************************************************************************/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!popQueue.empty()){
            pushQueue.push(popQueue.top());
            popQueue.pop();
        }
        pushQueue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!pushQueue.empty()){
            popQueue.push(pushQueue.top());
            pushQueue.pop();
        }
        int rst = -1;
        if(!popQueue.empty()) {
            rst = popQueue.top();
            popQueue.pop();
        }
        return rst;
    }
    
    /** Get the front element. */
    int peek() {
        while(!pushQueue.empty()){
            popQueue.push(pushQueue.top());
            pushQueue.pop();
        }
        if(!popQueue.empty()) return popQueue.top();
        return -1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pushQueue.empty() && popQueue.empty();
    }
    
private: 
    stack<int> pushQueue;
    stack<int> popQueue;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */