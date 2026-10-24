class Solution {
    void dfs(int n, vector<vector<int>>& adj,vector<int>&vis,int i,int par){
        vis[i]=1;

        for(int it:adj[i]){
            if(!vis[it]){
                dfs(n,adj,vis,it,i);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto&e :edges){ 
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        int c1=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(n,adj,vis,i,-1);
                c1++;
            }
        }
        return c1;
    }
};
