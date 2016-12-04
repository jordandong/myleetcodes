/*
Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).
https://en.wikipedia.org/wiki/Convex_polygon

Note:
1. There are at least 3 and at most 10,000 points.
2. Coordinates are in the range -10,000 to 10,000.
3. You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition).
   https://en.wikipedia.org/wiki/Simple_polygon
   In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.

Example 1:
[[0,0],[0,1],[1,1],[1,0]]
Answer: True
Explanation:
x--x
|  |
x--x

Example 2:
[[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False
Explanation:
x--------x
|        |
|        |
|   x    |
| /    \ |
|/      \|
x        x
*/

//https://en.wikipedia.org/wiki/Cross_product
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int N = points.size();
        long last_cp = 0;
        for(int i = 0; i < N; ++i){
            auto A = points[i];
            auto B = points[(i + 1) % N];
            auto C = points[(i + 2) % N];
            long cp = CrossProduct(A,B,C);
            if(last_cp * cp < 0)
               return false;
            last_cp  = cp;
        }
        return true;
    }

    int CrossProduct(vector<int>& A, vector<int>& B, vector<int>& C){
        int X_AB = B[0] - A[0];
        int Y_AB = B[1] - A[1];
        int X_AC = C[0] - A[0];
        int Y_AC = C[1] - A[1];
        return X_AB*Y_AC - X_AC * Y_AB;
    }
};

int main() {
    Solution s;
    vector<vector<int>> pt;
    pt = {{0,0},{0,1},{1,1},{1,0}};
    cout<<s.isConvex(pt)<<endl;
    pt= {{0,0},{0,10},{10,10},{10,0},{5,5}};
    cout<<s.isConvex(pt)<<endl;
    return 0;
}
