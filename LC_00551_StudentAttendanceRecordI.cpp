/*
You are given a string representing an attendance record for a student.
The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.

A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True

Example 2:
Input: "PPALLL"
Output: False

Hide Tags String
*/

class Solution {
public:
    bool checkRecord(string s) {
        int late_cnt = 0, absent_cnt = 0;
        for (auto c : s) {
            if (c == 'A') {
                if (++absent_cnt > 1)
                    return false;
                late_cnt = 0;
            } else if (c == 'L') {
                if (++late_cnt > 2)
                    return false;
            } else {
                late_cnt = 0;
            }
        }
        return true;
    }
};
