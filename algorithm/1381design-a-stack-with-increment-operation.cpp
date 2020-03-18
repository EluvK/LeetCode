class CustomStack {
public:
    int ind=0;
    int ms=0;
    vector<int> st;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        ms=maxSize;
    }

    void push(int x) {
        if(ind<ms){
            st[ind++]=x;
        }
    }

    int pop() {
        if(ind==0) return -1;
        else return st[--ind];
    }

    void increment(int k, int val) {
        int j=min(ms,min(ind,k));
        for(int i=0;i<j;++i) st[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
