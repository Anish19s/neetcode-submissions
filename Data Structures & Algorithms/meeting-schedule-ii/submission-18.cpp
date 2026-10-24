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
        int n=intervals.size();
        vector<int>start,end;

        for(int i=0;i<n;i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int i=0,j=0;
        int rooms=0,maxr=0;
        while(i<n){
            if(start[i]<end[j]){
                rooms++;
                maxr=max(maxr,rooms);
                i++;
            }
            else{
                rooms--;
                j++;
            }
        }
        return maxr;
    }
};
