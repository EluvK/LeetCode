bool cmp(vector<int> &a,vector<int> &b){
    for(int i=1;i<1010;++i){
        if(a[i]!=b[i]) return a[i]>b[i];
    }
    return a[0]<b[0];
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> v(26,vector<int>(1010));
        bool show[26]={false};
        for(int i=0;i<26;++i) v[i][0]=i;
        for(int i=0;i<votes.size();++i){
            for(int j=0;j<votes[i].size();++j){
                char c=votes[i][j];
                v[c-'A'][j+1]++;
                show[c-'A']=true;
            }
        }
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(int i=0;i<26;++i) if(show[v[i][0]]) ans+=(v[i][0]+'A');
        return ans;

    }
};
