class Solution {
    int mins(vector<int>&dist,vector<bool>&visited,int n){
        int mini=-1,minx=INT_MAX;
        for(int i=0;i<n;i++){
            if(!visited[i] && dist[i]<minx){
                mini=i;
                minx=dist[i];
            }
        }
        return mini;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>dist(n,INT_MAX);
        vector<bool>mst(n,0);
       /* for(auto& point:points){
            int u=point[0],v=points[1];

            adj[u][v]=
        }*/
        dist[0]=0;
        for(int i=0;i<n;i++){
            int u=mins(dist,mst,n);
            if(u==-1){
                break;
            }
            mst[u]=1;
            for(int j=0;j<n;j++){
                int a=points[u][0],b=points[u][1];
                int c=points[j][0],d=points[j][1];
                int cost=abs(a-c)+abs(b-d);
                if(!mst[j] && cost<dist[j]){
                    dist[j]=cost;
                }
            }
        }
        int t=0;
        for(int i=0;i<n;i++){
            t+=dist[i];
        }
        return t;
    }
};





