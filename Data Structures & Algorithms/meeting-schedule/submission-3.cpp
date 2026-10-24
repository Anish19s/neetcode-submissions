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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()){
            return 1;
        }
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){
            return a.end<b.end;
        });

        int n=intervals.size();

        int prevE=intervals[0].end;
        for(int i=1;i<n;i++){
            if(intervals[i].start<prevE){
                return 0;
            }
            prevE=intervals[i].end;
        }
        return 1;
    }
};
