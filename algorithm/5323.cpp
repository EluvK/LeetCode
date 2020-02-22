int cnt[10010]={0};
bool cmp(int &a,int &b){
    return cnt[a]!=cnt[b]?cnt[a]<cnt[b]:a<b;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        for(int i=1;i<10010;++i) cnt[i]=cnt[i>>1]+(i&1);
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};
