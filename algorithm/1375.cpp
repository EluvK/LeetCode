class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans=0;
        int len=light.size();
        vector<int> mx(len,light[0]);
        for(int i=1;i<len;++i){
            mx[i]=max(light[i],mx[i-1]);
        }
        for(int i=0;i<len;++i) if(mx[i]==i+1) ans++;
        return ans;
    }
};
