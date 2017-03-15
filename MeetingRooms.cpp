/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        for(int i = 0; i < n - 1; i++){
            if(intervals[i].end > intervals[i+1].start)
                return false;
        }
        return true;
    }
    
    static bool compare(Interval& interval1, Interval& interval2) {
        return interval1.start < interval2.start;
    }
};