/*
Given a data stream input of non-negative integers a1, a2, ..., an, ..., 
summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]

Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

Hide Tags Binary Search Tree
Hide Similar Problems (M) Summary Ranges
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
class SummaryRanges {
private:
    vector<Interval> intervals;
    
    int findInterval(int val) {
        int lo = 0, hi = intervals.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (val < intervals[mid].start) {
                hi = mid - 1;
            } else if (val > intervals[mid].start) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return hi;
    }
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        int idx = findInterval(val);
        if (idx != -1 && val <= intervals[idx].end) //contain val in interval
            return;
        if (idx != -1 && val - 1 == intervals[idx].end) //set current interval
            intervals[idx].end = val;
        else if (idx != intervals.size() - 1 && val + 1 == intervals[idx + 1].start) //set next interval
            intervals[idx + 1].start = val;
        else //add new interval
            intervals.insert(intervals.begin() + idx + 1, Interval(val, val));
            
        if (idx != -1 && intervals[idx].end + 1 == intervals[idx + 1].start) { //merge intervals
            intervals[idx + 1].start = intervals[idx].start;
            intervals.erase(intervals.begin() + idx);
        }
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
