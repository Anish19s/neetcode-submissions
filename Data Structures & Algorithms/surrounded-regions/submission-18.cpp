class Solution {
    void capture(vector<vector<char>>& board,int n,int m){
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1) && board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>>dirns={{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int row=p.first;
            int col=p.second;
            
            if(board[row][col]=='O'){
                board[row][col]='T';

                for(int i=0;i<4;i++){
                    int r=row+dirns[i][0];
                    int c=col+dirns[i][1];

                    if (r >= 0 && r < n &&
                        c >= 0 && c < m &&
                        board[r][c] == 'O') 
                    {
                        q.push({r, c});
                    }
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        capture(board,n,m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
