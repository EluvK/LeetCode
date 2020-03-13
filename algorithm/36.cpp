class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[10][10]={false},col[10][10]={false},block[10][10]={false};
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    int bi=i/3*3+j/3;
                    if(row[i][num]||col[j][num]||block[bi][num]) return false;
                    row[i][num]=true;
                    col[j][num]=true;
                    block[bi][num]=true;
                }
            }
        }
        return true;
    }
};
