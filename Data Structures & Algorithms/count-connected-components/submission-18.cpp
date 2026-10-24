class Solution {
    void dfs(int i,vector<int>&vis,vector<vector<int>>&adj){
        vis[i]=1;

        for(int x:adj[i]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
    }   
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int c1=0;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }


        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                c1++;
            }
        }
        return c1;
    }
};
