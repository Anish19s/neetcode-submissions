class Solution {
    void dfs(int i, vector<vector<int>>&adj,bool visited[],int n){
        visited[i]=1;
        for(int j=0;j<n;j++){
            if(!visited[j] && adj[i][j]){
                dfs(j,adj,visited,n);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n,vector<int>(n,0));
        for(auto&e:edges){
            int u=e[0],v=e[1];
            adj[u][v]=1;
            adj[v][u]=1;
        }
        bool visited[n]={0};
        int c1=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited,n);
                c1++;
            }
        }
        return c1;
    }
};
