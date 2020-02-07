class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int c=1,j=0;
        while(c<=n*n){
            for(int i=j;i<n-j;i++) ans[j][i]=c++;
            for(int i=j+1;i<n-j;i++) ans[i][n-j-1]=c++;
            for(int i=n-j-2;i>=j;i--) ans[n-j-1][i]=c++;
            for(int i=n-j-2;i>j;i--) ans[i][j]=c++;
            j++;
        }
        return ans;
    }
};
