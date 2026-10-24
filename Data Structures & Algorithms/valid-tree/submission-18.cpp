class Solution {
    void dfs(int i,vector<int>&vis,vector<vector<int>>&adj){
        vis[i]=1;

        for(int x:adj[i]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
    }
    bool cycle(int i,vector<int>&vis,vector<vector<int>>&adj,int par){
        vis[i]=1;

        for(int x:adj[i]){
            if(!vis[x]){
                if(cycle(x,vis,adj,i)){
                    return 1;
                }
            }
            else if(par!=x){
                return 1;
            }
        }
        return 0;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int c1=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                c1++;
            }
        }
        int a=0;
        vis=vector<int>(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycle(i,vis,adj,-1)){
                    a=1;
                    break;
                }
            }
        }
        return c1==1 && !a;
    }
};
