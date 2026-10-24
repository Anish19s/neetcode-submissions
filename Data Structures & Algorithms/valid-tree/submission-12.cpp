class Solution {
    void dfs(vector<vector<int>>&adj,int i, vector<int>&vis){
        vis[i]=1;

        for(auto&it:adj[i]){
            if(!vis[it]){
                dfs(adj,it,vis);
            }
        }
    }
    bool isCycle(vector<vector<int>>&adj,vector<int>&vis,int i,int par){
        vis[i]=1;
      
        for(auto&it:adj[i]){
            if(!vis[it]){
                if(isCycle(adj,vis,it,i)){
                    return 1;
                }
            }
            else if(par!=it){
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
        int c1=0,c2=0;
        vector<int>vis(n,0),vis2(n,0),rec(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c1++;
                dfs(adj,i,vis);
            }
        }
        int a=0;
         for(int i=0;i<n;i++){
            if(!vis2[i]){
                if(isCycle(adj,vis2,i,-1)){
                    a=1;
                    break;
                }
            }
        }
        return c1==1 && !a;
    }
};
