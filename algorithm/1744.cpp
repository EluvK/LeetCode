class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int len=arr.size(),ans=0;
        vector<vector<int>> v;
        vector<int> res(arr.size(),0);
        v.clear();
        for(int i=0;i<arr.size();i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int ind=v[i][1];
            int mx=0;
            for(int j=ind+1;j<=min(ind+d,len-1);j++){
                if(arr[j]>=arr[ind]) break;
                mx=max(res[j],mx);
            }
            for(int j=ind-1;j>=max(0,ind-d);j--){
                if(arr[j]>=arr[ind]) break;
                mx=max(res[j],mx);
            }
            res[ind]=mx+1;
            if(res[ind]>ans) ans=res[ind];
        }
        return ans;
    }
};
