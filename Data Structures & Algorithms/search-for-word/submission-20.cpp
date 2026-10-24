class Solution {
    bool dfs(vector<vector<char>>& board,int i,int j,string word,int n,int m,int a,vector<vector<bool>>&vis){
        if(a==word.size()){
            return 1;
        }
        if(i<0||i>n-1||j>m-1||j<0||vis[i][j]){
            return 0;
        }
        if(board[i][j]!=word[a]){
            return 0;
        }
        vis[i][j]=1;
        bool fond=dfs(board,i+1,j,word,n,m,a+1,vis)||dfs(board,i-1,j,word,n,m,a+1,vis)||dfs(board,i,j+1,word,n,m,a+1,vis)||dfs(board,i,j-1,word,n,m,a+1,vis);
        vis[i][j]=0;
        return fond;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int a=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,i,j,word,n,m,a,vis)){
                    return 1;
                }
            }
        }
        return 0;
    }
};
