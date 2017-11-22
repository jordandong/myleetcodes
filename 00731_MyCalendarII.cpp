/*
Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
Explanation: 
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
*/

class MyCalendarTwo {
private:
    unordered_map<double, int> mp;
    vector<vector<int>> events;
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        int s_cnt = 1, e_cnt = 1;
        for (auto e : events) {
            if (e[0] <= start && start < e[1])
                s_cnt++;
            if (e[0] < end && end <= e[1])
                e_cnt++;
        }
        if (s_cnt > 2 || e_cnt > 2)
            return false;
        
        vector<double> keys;
        for (auto e : mp) {
            if (start <= e.first && e.first <= end - 0.5) {
                if (e.second == 2)
                    return false;
                keys.push_back(e.first);
            }
        }
        for (auto k : keys)
            mp[k]++;
        if (mp.find(start) == mp.end())
            mp[(double)start] = s_cnt;
        if (mp.find(end) == mp.end())
            mp[end - 0.5] = e_cnt;
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
