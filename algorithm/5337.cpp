class Solution {
public:
    int d[5][500050]={0};
    int findTheLongestSubstring(string s) {
        vector<vector<int>> d(5,vector<int>(s.size()+1,0));
        vector<char> ch={'a','e','i','o','u'};
        for(int i=0;i<s.size();++i){
            for(int j=0;j<5;++j){
                d[j][i+1]=d[j][i];
                if(s[i]==ch[j])
                    d[j][i+1]++;
            }
        }

        int ans=0;
        for(int i=s.size();i>=0;--i){
            for(int j=0;j<=s.size()-i;++j){
                bool flag=true;
                for(int k=0;k<5;++k){
                    if((d[k][j+i]-d[k][j])%2){
                        flag=false;break;
                    }
                }
                if(flag) return i;
            }
        }
        return 0;
    }
};
