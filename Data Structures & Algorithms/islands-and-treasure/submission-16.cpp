class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;

        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }   
        int dirns[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dirns[i][0];
                int nc=c+dirns[i][1];

                if(nr<0||nr>n-1||nc<0||nc>m-1||grid[nr][nc]==0||grid[nr][nc]!=INT_MAX){
                    continue;
                }
                grid[nr][nc]=grid[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
};
