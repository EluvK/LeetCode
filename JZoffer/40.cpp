class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq;
        vector<int> ans;
        if(k==0) return ans;
        for(auto c:arr){
            if(pq.size()<k) pq.push(c);
            else{
                int f=pq.top();
                if(c>=f) continue;
                else{
                    pq.pop();
                    pq.push(c);
                }
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
