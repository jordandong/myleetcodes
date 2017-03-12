/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1

Note:
1. The number of time points in the given list is at least 2 and won't exceed 20000.
2. The input time is legal and ranges from 00:00 to 23:59.

Hide Tags String
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int N = timePoints.size();
        int v1 = getTime(timePoints[0]), v2 = 0, ans = 1440;
        for (int i = 0; i < timePoints.size(); i++) {
            v2 = getTime(timePoints[(i + 1) % N]);
            if (((i + 1) % N) == 0)
                v2 += 1440;
            ans = min(ans, v2 - v1);
            v1 = v2;
        }
        return ans;
    }
private:
    int getTime(string &t) {
        int v1 = 0, v2 = 0;
        for (auto &e : t) {
            if (e == ':') {
                v2 = v1 * 60;
                v1 = 0;
            } else {
                v1 = 10 * v1 + e - '0';
            }
        }
        return v2 + v1;
    }
};
