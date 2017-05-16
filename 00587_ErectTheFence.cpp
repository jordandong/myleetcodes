/*
There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden.
Your job is to fence the entire garden using the minimum length of rope as it is expensive.
The garden is well fenced only if all the trees are enclosed.
Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

Example 1:
Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:
5
4     T
3       T
2     t   T
1   T
0     T
  0 1 2 3 4 5

Example 2:
Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:
5
4
3
2   T T   T
1
0
  0 1 2 3 4 5
Even you only have trees in a line, you need to use rope to enclose them. 

Note:
1. All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
2. All input integers will range from 0 to 100.
3. The garden has at least one tree.
4. All coordinates are distinct.
5. Input points have NO order. No order required for output.

Hide Tags Geometry
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

//Graham Scan
class Solution {
public:
    // A utility function to return square of distance
    // between p1 and p2
    static int distSq(Point p1, Point p2) {
        return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    }
 
    // To find orientation of ordered triplet (p, q, r).
    // The function returns following values
    // 0 --> p, q and r are colinear
    // 1 --> Clockwise
    // 2 --> Counterclockwise
    static int orientation(Point p, Point q, Point r) {
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0) {
            return 0;  // colinear
        }
        return (val > 0) ? 1 : 2; // clock or counterclock wise
    }

    // A comparison function object using specified reference point
    struct pointsComparator {
        Point p0;
        bool operator() (const Point& p1, const Point& p2) {
 
            // Find orientation
            int o = orientation(p0, p1, p2);
            if (o == 0) {
                return distSq(p0, p2) >= distSq(p0, p1);
            }
            return o == 2;
        }
        pointsComparator(Point p) : p0(p) {}
    };
    
    // Prints convex hull of a set of n points.
    vector<Point> outerTrees(vector<Point> points) {
        int n = points.size();
        if (n <= 3) {
            return points;
        }
        // Find the bottommost point
        int ymin = points[0].y, min = 0;
        for (int i = 1; i < n; i++) {
            int y = points[i].y;
            // Pick the bottom-most or chose the left most point in case of tie
            if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
                ymin = points[i].y, min = i;
            }
        }
 
        // Place the bottom-most point at first position
        Point temp = points[0];
        points[0] = points[min];
        points[min] = temp;
        
        // Sort n-1 points with respect to the first point.
        // A point p1 comes before p2 in sorted ouput 
        // if p2 has larger polar angle (in counterclockwise direction) than p1
        // In the tied case, the one has smaller distance from p0 comes first
        Point p0 = points[0];
        sort(points.begin(), points.end(), pointsComparator(p0));
        //As we need to output all the vertices instead of extreme points
        //We need to sort the points with the same largest polar angle w.r.p. p0 in another way to break tie
        //Closer one comes last
        Point pn = points.back();        
        if (orientation(p0, points[1], pn) != 0) {
            int idx = n-1;
            while (orientation(p0, points[idx], pn) == 0) {
                idx--;
            }
            reverse(points.begin() + idx + 1, points.end());
        }
 
        // Create an empty stack and push first three points to it.
        vector<Point> vertices;
        vertices.push_back(points[0]);
        vertices.push_back(points[1]);
        vertices.push_back(points[2]);
        // Process remaining n-3 points
        for (int i = 3; i < n; i++) {
            // Keep removing top while the angle formed by
            // points next-to-top, top, and points[i] makes a right (in clockwise) turn
            while (orientation(vertices[vertices.size() - 2], vertices.back(), points[i]) == 1) {
                vertices.pop_back();
            }
            vertices.push_back(points[i]);
        }
        return vertices;
    }
};

//Andrew's monotone chain
class Solution {
public:
    static bool pointCompare(const Point& a, const Point& b) {
        //Sort the points by x-coordinates, break a tie by y-coordinate
        return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
    }
    
    bool isEqual(const Point& a, const Point& b) {
        return (a.x == b.x) && (a.y == b.y);    
    }
    
    int crossProduct(const Point& a, const Point& b, const Point& c) {
        // > 0 if a,b,c forms a counter clockwise turn
        // < 0 if a,b,c forms a clockwise turn
        // = 0 if a,b,c are collinear
        return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
    }
    
    vector<Point> outerTrees(vector<Point>& points) {
        //Sort the points
        sort(points.begin(), points.end(), pointCompare);
        vector<Point> upper;
        vector<Point> lower;
        //Find upper hull, in the dereasing order of x-coordinate
        for (int i = points.size() - 1; i >= 0; --i) {
            //Pop the top point if next_to_top, top, points[i] forms a right turn (in clockwise turn)
            while ((upper.size() > 1) 
                && (crossProduct(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) < 0)) {
                upper.pop_back();
            }
            upper.push_back(points[i]);
        }
        //Find lower hull, in the increasing order of x-coordinate 
        for (int i=0; i<points.size(); i++) {
            //Pop the top point if next_to_top, top, points[i] forms a right turn (in clockwise turn)
            while ((lower.size() > 1) 
                && (crossProduct(lower[lower.size() - 2], lower[lower.size() - 1], points[i]) < 0)) {
                lower.pop_back();
            }
            lower.push_back(points[i]);            
        }
        //Check the degenerate case if the convex hull is a line
        //In this case, lower == upper, we only need to check if upper[1] == lower[lower.size() - 2]
        if ((points.size() == 1) || (isEqual(upper[1],lower[lower.size() - 2]))) {
            return vector<Point>(upper.begin(), upper.end());
        }
        //In non-degenerate case, remove the starting point for both hulls
        //The right most one and the left most one is duplicated in both hulls
        vector<Point> vertices(upper.begin() + 1, upper.end());
        vertices.insert(vertices.end(), lower.begin() + 1, lower.end());
        return vertices;
    }
};
