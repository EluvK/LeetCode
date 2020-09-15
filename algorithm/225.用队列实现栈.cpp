/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
using namespace std;
class MyStack {
public:
    queue<int> q1, q2;
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            while (!q2.empty()) {
                int tmp = q2.front();
                q2.pop();
                q1.push(tmp);
            }
        } else {
            q2.push(x);
            while (!q1.empty()) {
                int tmp = q1.front();
                q1.pop();
                q2.push(tmp);
            }
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (!q1.empty()) {
            int tmp = q1.front();
            q1.pop();
            return tmp;
        } else {
            int tmp = q2.front();
            q2.pop();
            return tmp;
        }
    }

    /** Get the top element. */
    int top() {
        if (!q1.empty()) {
            int tmp = q1.front();
            return tmp;
        } else {
            int tmp = q2.front();
            return tmp;
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() { return q1.empty() && q2.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
