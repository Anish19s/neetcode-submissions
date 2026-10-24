class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
       
        dist[src]=0;
       for(int i=0;i<=k;i++){
            vector<int>temp=dist;

            for(auto& f:flights){
                int x=f[0],y=f[1],w=f[2];

                if(dist[x]!=INT_MAX && dist[x]+w<temp[y]){
                    temp[y]=dist[x]+w;
                }
            }
             dist=temp;
       }
       return dist[dst]==INT_MAX?-1:dist[dst];
       
    }
};
