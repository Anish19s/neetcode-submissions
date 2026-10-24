class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int n=intervals.size();
        if(n==0){
            return res;
        }
        sort(intervals.begin(),intervals.end());


        for(int i=0,j=1;j<n;i++,j++){
            if(intervals[i][1]<intervals[j][0]){
                res.push_back(intervals[i]);
            }
            else{
                intervals[j][0]=min(intervals[i][0],intervals[j][0]);
                intervals[j][1]=max(intervals[i][1],intervals[j][1]);
            }
        }
        res.push_back(intervals[n-1]);
        return res;
    }
};
