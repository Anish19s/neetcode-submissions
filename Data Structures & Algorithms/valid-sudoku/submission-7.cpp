class Solution {
    bool isSafe(int row,int col,vector<vector<char>>& board,char val){
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i]==val){
                return 0;
            }
            if(i!=row && board[i][col]==val){
                return 0;
            }
            int boxr=3*(row/3)+i/3;
            int boxc=3*(col/3)+i%3;
            if((boxr!=row||boxc!=col) && board[boxr][boxc]==val){
                return 0;
            }
        }
        return 1;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isSafe(i,j,board,board[i][j])){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};
