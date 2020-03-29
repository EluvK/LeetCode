class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &str:words) reverse(str.begin(),str.end());
        sort(words.begin(),words.end());
        int ans=0;
        for(int i=0;i<words.size()-1;++i){
            int sz=words[i].size();
            if(words[i]==words[i+1].substr(0,sz)) continue;
            ans+=sz+1;
        }
        return ans+words.back().size()+1;
    }
};
