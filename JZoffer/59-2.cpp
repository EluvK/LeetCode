class MaxQueue {
public:
    queue<int> q;
    deque<int> dq;
    MaxQueue() {

    }

    int max_value() {
        if(q.empty()) return -1;
        return dq.front();
    }

    void push_back(int value) {
        q.push(value);
        while(!dq.empty()&&value>dq.back()) dq.pop_back();
        dq.push_back(value);
    }

    int pop_front() {
        if(q.empty()) return -1;
        int ans=q.front();
        q.pop();
        if(ans==dq.front()) dq.pop_front();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
