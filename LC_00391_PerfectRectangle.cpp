/*
Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.
Each rectangle is represented as a bottom-left point and a top-right point.
For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


Example 1:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]
Return true. All 5 rectangles together form an exact cover of a rectangular region.

Example 2:
rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]
Return false. Because there is a gap between the two rectangular regions.

Example 3:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]
Return false. Because there is a gap in the top center.

Example 4:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]
Return false. Because two of the rectangles overlap with each other.
*/

/*
https://discuss.leetcode.com/topic/55923/o-n-solution-by-counting-corners-with-detailed-explaination

Consider how the corners of all rectangles appear in the large rectangle if there's a perfect rectangular cover.
Rule 1: The local shape of the corner has to follow one of the three following patterns

Corner of the large rectangle (blue): it occurs only once among all rectangles
T-junctions (green): it occurs twice among all rectangles
Cross (red): it occurs four times among all rectangles
Rule 2: A point can only be the top-left corner of at most one sub-rectangle. Similarly it can be the top-right/bottom-left/bottom-right corner of at most one sub-rectangle. Otherwise overlaps occur.

Proof of correctness

Obviously, any perfect cover satisfies the above rules. So the main question is whether there exists an input which satisfy the above rules, yet does not compose a rectangle.

First, any overlap is not allowed based on the above rules because

aligned overlap like [[0, 0, 1, 1], [0, 0, 2, 2]] are rejected by Rule 2.
unaligned overlap will generate a corner in the interior of another sub-rectangle, so it will be rejected by Rule 1.
Second, consider the shape of boundary for the combined shape. The cross pattern does not create boundary. The corner pattern generates a straight angle on the boundary, and the T-junction generates a straight border.
So the shape of the union of rectangles has to be rectangle(s).

Finally, if there are more than two non-overlapping rectangles, at least 8 corners will be found, and cannot be matched to the 4 bounding box corners (be reminded we have shown that there is no chance of overlapping).
So the cover has to be a single rectangle if all above rules are satisfied.

Algorithm

Step1: Based on the above idea we maintain a mapping from (x, y)->mask by scanning the sub-rectangles from beginning to end.

(x, y) corresponds to corners of sub-rectangles
mask is a 4-bit binary mask. Each bit indicates whether there have been a sub-rectangle with a top-left/top-right/bottom-left/bottom-right corner at (x, y). If we see a conflict while updating mask, it suffice to return a false during the scan.
In the meantime we obtain the bounding box of all rectangles (which potentially be the rectangle cover) by getting the upper/lower bound of x/y values.
Step 2: Once the scan is done, we can just browse through the unordered_map to check the whether the mask corresponds to a T junction / cross, or corner if it is indeed a bounding box corner.
*/

class Solution {
private:
    inline bool insert_corner(unordered_map<int, unordered_map<int, int>>& corner_count, int x, int y, int pos) {
        int& m = corner_count[x][y];
        if (m & pos)
            return false;
        m |= pos;
        return true;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // step 1: counting
        unordered_map<int, unordered_map<int, int>> corner_count;
        int minx = INT_MAX, maxx=INT_MIN, miny=INT_MAX, maxy=INT_MIN;
        for (auto& rect : rectangles) {
            minx = min(minx, rect[0]);
            maxx = max(maxx, rect[2]);
            miny = min(miny, rect[1]);
            maxy = max(maxy, rect[3]);
            if (!insert_corner(corner_count, rect[0], rect[1], 1)) //BL - 1(0001)
                return false;
            if (!insert_corner(corner_count, rect[2], rect[1], 2)) //BR - 2(0010)
                return false;
            if (!insert_corner(corner_count, rect[0], rect[3], 4)) //TL - 4(0100)
                return false;
            if (!insert_corner(corner_count, rect[2], rect[3], 8)) //TR - 8(1000)
                return false;
        }
    
        //step2: checking
        bool valid_corner[16] = {false};
        bool valid_interior[16] = {false};
        valid_corner[1] = valid_corner[2] = valid_corner[4] = valid_corner[8] = true; //outer points
        //BL + BR = 3, BL + TL = 5, BR + TR = 10, TL + TR = 12, BL + BR + TL + TR = 15
        valid_interior[3] = valid_interior[5] = valid_interior[10] = valid_interior[12] = valid_interior[15] = true;
    
        for (auto itx = corner_count.begin(); itx != corner_count.end(); ++itx) {
            int x = itx->first;
            for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
                int y = ity->first;
                int mask = ity->second;
                if ((x == minx || x == maxx) && (y == miny || y == maxy)) {
                    if ( !valid_corner[mask] )
                        return false;
                } else {
                    if ( !valid_interior[mask])
                        return false;
                }
            }
        }
        return true;
    }
};
