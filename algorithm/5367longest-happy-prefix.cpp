const int maxn=1e5+10;
class Solution {
public:
    int nxt[maxn];
    string longestPrefix(string s) {
        if(s.size()<2) return "";
        string str="x"+s;
        int len=s.size();
        memset(nxt,0,sizeof(nxt));
        int i,j;
        for(i=2,j=0;i<=len;++i){
            for(;j&&str[j+1]!=str[i];j=nxt[j]);
            if(str[j+1]==str[i]) ++j;
            nxt[i]=j;
        }

        j=nxt[len];
        for(;j;j=nxt[j])
            if(str[j]==str[len]) return s.substr(0,j);

        return "";
    }
};
