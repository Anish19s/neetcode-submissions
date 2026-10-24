class Solution {
    int find(vector<int>&parent,int a){
        if(parent[a]==a){
            return a;
        }
        return parent[a]=find(parent,parent[a]);
    }
    void unions(vector<int>&parent,int a,int b){
         parent[find(parent,b)]=find(parent,a);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>fin(2);
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            int a=edges[i][0]-1,b=edges[i][1]-1;
            if(find(parent,a)==find(parent,b)){
                fin[0]=a+1;
                fin[1]=b+1;
            }
            else{
                unions(parent,a,b);
            }
        }
        return fin;
    }
};
