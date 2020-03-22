class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int d[80010]={0};
        int ans=0;
        for(int i=0;i<A.size();++i) d[A[i]]++;
        for(int i=0;i<80010;++i){
            if(d[i]==0) continue;
            ans+=d[i]-1;
            d[i+1]+=d[i]-1;
        }
        return ans;
    }
};
