/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
--------------------(C, D)
|                    |
|                    |
|         |--------- |--------------(G,H)
|         |          |                |
(A, B)---------------|                |
          |                           |
          |                           |
         (E,F)-------------------------

Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.

Hide Tags Math
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l_1 = C - A;
        int h_1 = D - B;
        int l_2 = G - E;
        int h_2 = H - F;

        if (A >= G || E >= C || B >= H || F>= D)
            return l_1*h_1 + l_2*h_2;

        int l_3 = min(C, G) - max(A, E);
        int h_3 = min(D, H) - max(B, F);
        return l_1*h_1 + l_2*h_2 - l_3*h_3;
        }
};
