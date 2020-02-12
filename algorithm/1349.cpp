class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m=seats.size(),n=seats[0].size();
        vector<vector<int>> dp(m+1,vector<int>(1<<n,0));
        vector<int> bit_seats(m+1,0);
        vector<int> cnt1(1<<n,0);
        for(int i=1;i<1<<n;++i) cnt1[i]=cnt1[i>>1]+(i&1);
        for(int i=1;i<=m;++i){
            for(int j=0;j<n;j++){
                if(seats[i-1][j]=='#') bit_seats[i]|=1<<j;
            }
        }
        for(int i=1;i<=m;++i){
            for(int j=0;j<(1<<n);++j){
                if(!(j&bit_seats[i])&&!(j&j<<1)&&!(j&j>>1)){
                    for(int k=0;k<(1<<n);++k){
                        if(!(j&k>>1)&&!(j&k<<1)){
                            dp[i][j]=max(dp[i][j],dp[i-1][k]+cnt1[j]);
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            ans=max(dp[m][i],ans);
        }
        return ans;
    }
};
