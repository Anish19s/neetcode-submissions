class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,vector<int>>>pq;

        for(int i=0;i<points.size();i++){
            int num=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            pq.push({num,points[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        for(int i=0;i<k;i++){
            auto p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};
