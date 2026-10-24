class Solution {
    void dfs(int n, vector<vector<int>>& adj,vector<int>&vis,int i){
        vis[i]=1;
        for(int x:adj[i]){
            if(!vis[x]){
                dfs(n,adj,vis,x);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n);
        int c1=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c1++;
                dfs(n,adj,vis,i);
            }
        }
        return c1;
    }
};
