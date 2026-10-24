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
       sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){
            return a.end<b.end;
       });
       int prevE=intervals[0].end;
       for(int i=1;i<intervals.size();i++){
        if(prevE>intervals[i].start){
            return 0;
        }
        else{
            prevE=intervals[i].end;
        }
       }
       return 1;
    }
};
