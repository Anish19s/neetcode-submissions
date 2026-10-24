class Solution {
    int mins(vector<int>&dist,vector<bool>&visited,int n){
        int min=-1,minV=INT_MAX;
        for(int i=0;i<n;i++){
            if(!visited[i] && dist[i]<minV){
                minV=dist[i];
                min=i;
            }
        }
        return min;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        vector<bool> visited(n,false);
        vector<int> dist(n,INT_MAX);
        dist[k-1]=0;
        for(auto& time:times){
            int x=time[0]-1,y=time[1]-1,w=time[2];
            adj[x][y]=w;
        }
        for(int i=0;i<n-1;i++){
            int u=mins(dist,visited,n);
            if(u==-1){
                break;
            }
            visited[u]=1;
            for(int j=0;j<n;j++){
                if(!visited[j] && adj[u][j]!=INT_MAX && dist[u]+adj[u][j]<dist[j]){
                    dist[j]=dist[u]+adj[u][j];
                }
            }
        }
        int sum=0;
        for(int d:dist){
            if(d==INT_MAX){
                return -1;
            }
            sum=max(sum,d);
        }
        return sum;
    }
};






