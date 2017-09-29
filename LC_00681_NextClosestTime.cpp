/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits.
There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid.
For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:
Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
             It is not 19:33, because this occurs 23 hours and 59 minutes later.

Example 2:
Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
             It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
*/

class Solution {
public:
    string nextClosestTime(string time) {
        time = time.substr(0, 2) + time.substr(3);
        string stime = time, ntime;
        sort(stime.begin(), stime.end());
        for (int x = 3; x >= 0; x--) {
            for (auto y : stime) {
                if (y <= time[x])
                    continue;
                if ((x == 2 && y > '5') || (x == 1 && time[x - 1] == '2' && y > '3') || (x == 0 && y > '2'))
                    continue;
                ntime = time;
                ntime[x] = y;
                for (int i = 3; i > x; i--)
                    ntime[i] = stime[0];
                if ((stoi(ntime.substr(0, 2)) < 24) && (stoi(ntime.substr(2)) < 60))
                    return ntime.substr(0, 2) + ":" + ntime.substr(2);
            }
        }
        ntime = string(2, stime[0]);
        return ntime + ":" + ntime;
    }
};
