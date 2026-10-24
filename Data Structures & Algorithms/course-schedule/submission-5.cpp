class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ind(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto& p:prerequisites){
            ind[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        int c1=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            c1++;
            for(int ne:adj[node]){
                ind[ne]--;
                if(ind[ne]==0){
                    q.push(ne);
                }
            }
        }
        return c1==numCourses;
    }
};
