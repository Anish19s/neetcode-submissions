class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dirns={{-1,0},{1,0},{0,-1},{0,1}};
        int c1=0;
        while(!q.empty()){
            int l=q.size();
            int a=0;
            for(int j=0;j<l;j++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int r=row+dirns[i][0];
                    int c=col+dirns[i][1];

                    if(r<0||r>=n||c<0||c>=m||grid[r][c]==0){
                        continue;
                    }

                    if(grid[r][c]==1){
                        grid[r][c]=2;
                        a=1;
                        q.push({r,c});
                    }
                }
            }
            if(a){
           c1++;}
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return c1;
    }
};
