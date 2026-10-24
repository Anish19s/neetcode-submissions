class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0]; // minimum possible time
        int right = n*n;       // maximum possible time

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        auto canReach = [&](int t) {
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int,int>> q;
            if(grid[0][0] <= t){
                q.push({0,0});
                visited[0][0] = true;
            }

            while(!q.empty()){
                auto [r,c] = q.front(); q.pop();
                if(r == n-1 && c == n-1) return true;

                for(auto &d : dirs){
                    int nr = r + d[0], nc = c + d[1];
                    if(nr >=0 && nr < n && nc >=0 && nc < n && !visited[nr][nc] && grid[nr][nc] <= t){
                        visited[nr][nc] = true;
                        q.push({nr,nc});
                    }
                }
            }

            return false;
        };

        // Binary search on time
        while(left < right){
            int mid = left + (right - left)/2;
            if(canReach(mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};
