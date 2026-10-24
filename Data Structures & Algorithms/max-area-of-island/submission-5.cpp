class Solution {
    void dfs(vector<vector<int>>& grid,int &c1,int i,int j,int m,int n){
        if(i<0||i>=m||j<0||j>=n){
            return;
        }
        if(grid[i][j]==0){
            return;
        }
        c1++;
        grid[i][j]=0;
        dfs(grid,c1,i+1,j,m,n);
        dfs(grid,c1,i-1,j,m,n);
        dfs(grid,c1,i,j+1,m,n);
        dfs(grid,c1,i,j-1,m,n);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),max=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int c1=0;
                    dfs(grid,c1,i,j,m,n);
                    if(c1>max){
                        max=c1;
                    }
                }
            }
        }
        return max;
    }
};
