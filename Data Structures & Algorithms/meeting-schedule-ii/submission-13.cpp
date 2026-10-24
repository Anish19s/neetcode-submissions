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
        vector<int>start(n),end(n);
         for(int i=0;i<intervals.size();i++){
        start[i]=intervals[i].start;
        end[i]=intervals[i].end;
       }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int i=0,j=0,rooms=0,c1=0;

        while(i<n){
            if(start[i]<end[j]){
                c1++;
                rooms=max(rooms,c1);
                i++;
            }
            else{
                c1--;
                j++;
            }
        }
        return rooms;
    }
};
