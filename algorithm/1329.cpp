class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.size()==0) return mat;
        int m=mat.size(),n=mat[0].size();
        bool ck=true;
        while(ck){
            ck=false;
            for(int i=0;i<m-1;i++){
                for(int j=0;j<n-1;j++){
                    if(mat[i][j]>mat[i+1][j+1]){
                        swap(mat[i][j],mat[i+1][j+1]);
                        ck=true;
                    }
                }
            }
        }
        return mat;
    }
};
