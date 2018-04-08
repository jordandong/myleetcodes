/*
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.

.
.
. . .

Notes:
3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.
*/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    int u1 = points[j][0] - points[i][0], u2 = points[k][0] - points[i][0];
                    int v1 = points[j][1] - points[i][1], v2 = points[k][1] - points[i][1];
                    // = 0.5|a||b|sin@ = 0.5|a||b|sqrt(1-cos@^2) = 0.5sqrt(|a|^2|b|^2 - |a|^2|b|^2cos@^2)
                    // = 0.5sqrt(|a|^2|b|^2 - (|a||b|cos@)^2) = 0.5sqrt(|a|^2|b|^2 - (a.b)^2)
                    // = 0.5sqrt((u1^2 + v1^2)(u2^2 + v2^2) - (u1u2 + v1v2)^2)
                    // = 0.5sqrt((u1^2v2^2 + v1^2u2^2) - 2u1u2v1v2)
                    // = 0.5sqrt((u1v2 - v1u2)^2) = 0.5(u1v2-v1u2)
                    ans = max(ans, 0.5*abs(u1*v2 - v1*u2));
                }
            }
        }
        return ans;
    }
};
