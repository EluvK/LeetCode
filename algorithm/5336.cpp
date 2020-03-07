class Solution {
public:
    string sortString(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();++i) mp[s[i]]++;
        string ans="";
        while(ans.size()!=s.size()){
            for(int i=0;i<26;++i){
                if(mp['a'+i]>0){
                    ans+=('a'+i);
                    mp['a'+i]--;
                }
            }
            for(int i=25;i>=0;--i){
                if(mp['a'+i]>0){
                    ans+=('a'+i);
                    mp['a'+i]--;
                }
            }
        }
        return ans;
    }
};
