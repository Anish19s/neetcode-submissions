class Solution {
    unordered_map<int,int>parent;

    void dfs(int i,vector<vector<int>>&adj,bool visited[],int n){
        visited[i]=1;
        for(int j=0;j<n;j++){
            if(!visited[j] && adj[i][j]){
                dfs(j,adj,visited,n);
            }
        }
    }
    bool dfs2(int i,vector<vector<int>>&adj,bool visited[],int n){
        visited[i]=1;
        for(int j=0;j<n;j++){
            if(adj[i][j]){
            if(!visited[j]){
                parent[j]=i;
                if(dfs2(j,adj,visited,n)){
                    return 1;
                };
            }
            else if(parent[i]!=j){
                return 1;
            }}
        }
        return 0;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n,vector<int>(n,0));
       for(auto&e:edges){
            int u=e[0],v=e[1];
             adj[u][v]=1;
             adj[v][u]=1;
       }
        int c1=0;
        bool visited[n]={0};
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited,n);
                c1++;
            }
        }
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        parent.clear();
        parent[0]=-1;
        bool res=dfs2(0,adj,visited,n);
        return !res && c1==1;

    }














};
