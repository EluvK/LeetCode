/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
using namespace std;
class MinStack {
public:
    stack<int> st;
    multiset<int> mst;
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        st.push(x);
        mst.insert(x);
    }

    void pop() {
        int tmp = st.top();
        st.pop();
        mst.erase(mst.find(tmp));
    }

    int top() { return st.top(); }

    int getMin() { return *mst.begin(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
