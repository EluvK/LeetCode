/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
using namespace std;
class MyQueue {
private:
    stack<int> a;
    stack<int> b;

public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { a.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto r = peek();
        b.pop();
        return r;
    }

    /** Get the front element. */
    int peek() {
        if (b.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        auto r = b.top();
        return r;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return a.empty() && b.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
