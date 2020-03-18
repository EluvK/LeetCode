class Solution {
public:
    int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
    bool hasGroupsSizeX(vector<int>& deck) {
        int cnt[10010]={0};
        for(auto c:deck) cnt[c]++;
        int res=cnt[deck[0]];
        for(int i=0;i<10000;++i){
            if(cnt[i]){
                res=gcd(res,cnt[i]);
            }
        }
        return res==1?false:true;
    }
};
