/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Hide Tags Array Sort
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool interval_cmp(Interval &a, Interval &b){
     return a.start < b.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() < 2)
            return intervals;
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), interval_cmp);
        Interval cur = intervals[0];
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i].start <= cur.end){
                cur.start = min(intervals[i].start, cur.start);
                cur.end = max(intervals[i].end, cur.end);
                continue;
            }
            res.push_back(cur);
            cur = intervals[i];
        }
        res.push_back(cur);
        return res;
    }
};
