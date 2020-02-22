class Solution {
public:
    int numberOfSubstrings(string s) {
        int len=s.size();
        if(len<3) return 0;
        queue<int> qa,qb,qc;
        for(int i=0;i<len;++i){
            if(s[i]=='a') qa.push(i);
            else if(s[i]=='b') qb.push(i);
            else qc.push(i);
        }
        int ans=0,st=0;
        while(qa.size()&&qb.size()&&qc.size()){
            if(s[st]=='a'){
                qa.pop();
                ans+=len-max(qb.front(),qc.front());
            }else if(s[st]=='b'){
                qb.pop();
                ans+=len-max(qa.front(),qc.front());
            }else{
                qc.pop();
                ans+=len-max(qa.front(),qb.front());
            }
            st++;
            // cout<<ans<<endl;
        }
        return ans;
    }
};
