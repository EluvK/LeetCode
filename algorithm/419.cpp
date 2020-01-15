#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size()==0||board[0].size()==0) return 0;
        int res=0;
        if(board[0][0]=='X') res=1;
        for(int i=1;i<board.size();i++){
            if(board[i][0]=='X'&&board[i-1][0]=='.') res++;
        }
        for(int i=1;i<board[0].size();i++){
            if(board[0][i]=='X'&&board[0][i-1]=='.') res++;
        }
        for(int i=1;i<board.size();i++){
            for(int j=1;j<board[i].size();j++){
                if(board[i][j]=='X'&&board[i-1][j]=='.'&&board[i][j-1]=='.') res++;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<char>> v={{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    Solution s;
    cout<<s.countBattleships(v);
    return 0;
}
