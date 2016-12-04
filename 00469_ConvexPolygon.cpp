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
discussion 599
