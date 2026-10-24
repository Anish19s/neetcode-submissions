class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inD(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto& p:prerequisites){
            inD[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inD[i]==0){
                q.push(i);
            }
        }
        int c1=0;
        vector<int>arr(numCourses);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            c1++;
            arr.push_back(x);
            for(int ne:adj[x]){
                inD[ne]--;
                if(inD[ne]==0){
                    q.push(ne);
                }
            }
        }
        if(numCourses==c1){
            return arr;}
        vector<int> brr;
        return brr;
    }
};
