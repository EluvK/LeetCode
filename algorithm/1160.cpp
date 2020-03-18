class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26]={0};
        for(char c:chars) cnt[c-'a']++;
        int ans=0;
        for(int i=0;i<words.size();++i){
            int tmp[26];
            memcpy(tmp,cnt,26*sizeof(int));
            bool flag=true;
            for(int j=0;j<words[i].size();++j){
                if(--tmp[words[i][j]-'a']<0){
                    flag=false;break;
                }
            }
            if(flag) ans+=words[i].size();
        }
        return ans;
    }
};
