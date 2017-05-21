/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True

Note:
1. All the input integers are in the range [-10000, 10000].
2. A valid square has four equal sides with positive length and four equal angles (90-degree angles).
3. Input points have no order.

Hide Tags Math
*/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d2 = distSq(p1, p2);  // from p1 to p2
        int d3 = distSq(p1, p3);  // from p1 to p3
        int d4 = distSq(p1, p4);  // from p1 to p4
        
        if(!d2 || !d3 || !d4)
            return false;
 
        // If lengths (p1, p2) and (p1, p3) are same, then following conditions must met to form a square.
        // 1) Square of length of (p1, p4) is same as twice the square of (p1, p2)
        // 2) p4 is at same distance from p2 and p3
        if (d2 == d3 && 2*d2 == d4) {
            int d = distSq(p2, p4);
            return (d == distSq(p3, p4) && d == d2);
        }
 
        // The below two cases are similar to above case
        if (d3 == d4 && 2*d3 == d2) {
            int d = distSq(p2, p3);
            return (d == distSq(p2, p4) && d == d3);
        }
        
        if (d2 == d4 && 2*d2 == d3) {
            int d = distSq(p2, p3);
            return (d == distSq(p3, p4) && d == d2);
        }
 
        return false;
    }
private:
    int distSq(vector<int>& p, vector<int>& q) {
        return (p[0] - q[0]) * (p[0] - q[0]) +
               (p[1] - q[1]) * (p[1] - q[1]);
    }
};

//failed at (0,0),(0,2),(-1,√3),(1,√3), but interger is fine
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> mp;
        mp[distSq(p1, p2)]++;
        mp[distSq(p1, p3)]++;
        mp[distSq(p1, p4)]++;
        mp[distSq(p2, p3)]++;
        mp[distSq(p2, p4)]++;
        mp[distSq(p3, p4)]++;
        int v4 = -1, v2 = -1;
        for (auto e : mp) {
            if (e.second == 4)
                v4 = e.first;
            else if (e.second == 2)
                v2 = e.first;
        }
        
        return v2 > 0 && v4 > 0 && v4 < v2;
    }
private:
    int distSq(vector<int>& p, vector<int>& q) {
        return (p[0] - q[0]) * (p[0] - q[0]) +
               (p[1] - q[1]) * (p[1] - q[1]);
    }
};

//failed at (0,0),(0,2),(-1,√3),(1,√3), but interger is fine
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12 = distSq(p1, p2);
        int d13 = distSq(p1, p3);
        int d14 = distSq(p1, p4);
        int d23 = distSq(p2, p3);
        int d24 = distSq(p2, p4);
        int d34 = distSq(p3, p4);
        unordered_set<int> m({d12, d13, d14, d23, d24, d34});
        
        return !m.count(0) && m.size() == 2;
    }
private:
    int distSq(vector<int>& p, vector<int>& q) {
        return (p[0] - q[0]) * (p[0] - q[0]) +
               (p[1] - q[1]) * (p[1] - q[1]);
    }
};
