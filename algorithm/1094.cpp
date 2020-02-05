class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int len[1010]={0},mx=0;
        for(int i=0;i<trips.size();i++){
            int n=trips[i][0],st=trips[i][1],ed=trips[i][2];
            len[st]+=n;
            len[ed]-=n;
            mx=max(ed,mx);
        }
        for(int i=1;i<=mx;i++){
            len[i]+=len[i-1];
            if(len[i]>capacity) return false;
        }
        return true;

    }
};
