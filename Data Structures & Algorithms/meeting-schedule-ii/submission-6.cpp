/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==1){
            return 1;
        }
        int c1=1;
        int n=intervals.size();

        vector<int>start(n);
        vector<int>end(n);

        for(int i=0;i<n;i++){
            start[i]=intervals[i].start;
            end[i]=intervals[i].end;
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0,j=0;
        int rooms=0,maxR=0;

        while(i<n){
            if(start[i]<end[j]){
                rooms++;
                maxR=max(maxR,rooms);
                i++;
            }
            else{
                rooms--;
                j++;
            }
        }
        return maxR;
    }
};





