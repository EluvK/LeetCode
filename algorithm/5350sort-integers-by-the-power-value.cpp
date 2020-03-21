class Solution {
public:
    int cnt[1010]={0};
    void cal(int i){
        int tmp=i;
        int t=0;
        while(i>1000||cnt[i]==0){
            if(i%2) i=i*3+1;
            else i=i/2;
            t++;
        }
        cnt[tmp]=t+cnt[i];
    }
    int getKth(int lo, int hi, int k) {
        cnt[1]=1;
        for(int i=2;i<=1000;i++){
            cal(i);
        }
        if(hi==lo) return lo;
        vector<int> ans(hi-lo+1);
        iota(ans.begin(),ans.end(),lo);
        sort(ans.begin(),ans.end(),[&](int a,int b){
            return cnt[a]!=cnt[b]?cnt[a]<cnt[b]:a<b;
        });

        return ans[k-1];
    }
};
