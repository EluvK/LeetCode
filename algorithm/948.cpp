class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n=tokens.size();
        int l=0,r=n-1;
        int ans=0;
        sort(tokens.begin(),tokens.end());
        if(!n||P<tokens[0]) return ans;
        while(l<r||(l==r&&tokens[l]<=P)){
            while(l<n&&P>=tokens[l]){
                // cout<<" + "<<l<<endl;
                P-=tokens[l++];
                ans++;
            }
            if(l<r){
                // cout<<" - "<<r<<endl;
                P+=tokens[r--];
                ans--;
            }
        }
        return ans;
    }
};
