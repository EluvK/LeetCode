class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int rx,ry;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j]=='R'){
                    rx=i;ry=j;
                }
        int ans=0;
        for(int k=0;k<4;++k){
            int nx=rx+dx[k],ny=ry+dy[k];
            while(nx>=0&&ny>=0&&nx<board.size()&&ny<board[0].size()){
                if(board[nx][ny]=='p') {ans++;break;};
                if(board[nx][ny]=='B') break;
                else {
                    nx=nx+dx[k];
                    ny=ny+dy[k];
                }
            }
        }
        return ans;
    }
};
