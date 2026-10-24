class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int c1=0;
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        int prevEnd=intervals[0][1];
        for(int j=1;j<n;j++){
            if(intervals[j][0]<prevEnd){
                    c1++;
            }
            else{
                prevEnd=intervals[j][1];
            }
        }
        return c1;
    }
};
