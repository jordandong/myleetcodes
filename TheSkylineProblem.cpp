/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

Buildings  Skyline Contour


The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:
The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]

Credits:
Special thanks to @stellari for adding this problem, creating these two awesome images and all test cases.

Hide Tags Divide and Conquer Heap
*/

//T:O(NlogN) S:O(N)
class Solution {
public:
    enum{
        start = 0,
        end,
        height
    };
    vector<pair<int, int>> getSkyline(vector<vector<int> > &buildings) {
        int N = buildings.size();
        if(N == 0)
            return vector<pair<int, int> >();
        vector<vector<int> > res = getSkylineHelper(buildings, 0, N - 1);
        vector<pair<int, int> > res_p;
        res_p.push_back(make_pair(res[0][start], res[0][height]));
        for (int i = 1; i < res.size(); i++) {
            if(res[i - 1][end] != res[i][start])
                res_p.push_back(make_pair(res[i - 1][end], 0));
            res_p.push_back(make_pair(res[i][start], res[i][height]));
        }
        res_p.push_back(make_pair(res.back()[end], 0));
        return res_p;
    }
    
    // Divide
    vector<vector<int> > getSkylineHelper(vector<vector<int>>& buildings, int l, int r) {
        if (l == r)
            return vector<vector<int> > (1, buildings[l]);

        int mid = l + (r - l) / 2;
        auto l_rtn = getSkylineHelper(buildings, l, mid);
        auto r_rtn = getSkylineHelper(buildings, mid + 1, r);
        return getSkylineMerge(l_rtn, r_rtn);
    }
    
    // Merge
    vector<vector<int> > getSkylineMerge(vector<vector<int>>& l_rtn, vector<vector<int>>& r_rtn) {
        int i = 0, j = 0;
        vector<vector<int>> rtn;
        
        while (i < l_rtn.size() && j < r_rtn.size()) {
            if (l_rtn[i][end] < r_rtn[j][start]) { //l is separated 
                rtn.push_back(l_rtn[i++]);
            } else if (r_rtn[j][end] < l_rtn[i][start]) { //r is separated
                rtn.push_back(r_rtn[j++]);
            } else if (l_rtn[i][start] <= r_rtn[j][start]) {//small start is always as the first argu
                MergeInterval(rtn, l_rtn[i], i, r_rtn[j], j);
            } else {
                MergeInterval(rtn, r_rtn[j], j, l_rtn[i], i);
            }
        }
        
        // remaining l/r_rtn
        if(i < l_rtn.size())
            rtn.insert(rtn.end(), l_rtn.begin() + i, l_rtn.end());
        if(j < r_rtn.size())
            rtn.insert(rtn.end(), r_rtn.begin() + j, r_rtn.end());
        return rtn;
    }
    
    void MergeInterval(vector<vector<int> >& rtn, vector<int>& x, int& x_i, vector<int>& y, int& y_i) {
        if (x[end] <= y[end]) { // x overlays y
            if (x[height] > y[height]) {
                if (x[end] != y[end]) { //x covers y, add x, update y start
                    rtn.push_back(x);
                    x_i++;
                    y[start] = x[end];
                } else { // x covers y fully, remove y
                    y_i++; 
                }
            } else if (x[height] == y[height]) { //x connects y with same height, update y start with smaller one, remove x
                y[start] = x[start];
                x_i++;
            } else { // y covers x
                if (x[start] != y[start]) { //add part of x
                    rtn.push_back(vector<int>{x[start], y[start], x[height]});
                }
                x_i++; //remove x
            }
        } else { //x contains whole y
            if (x[height] >= y[height]) { //x fully covers y, remove y, update x start with the remaning
                y_i++;
            } else { //add first part of x and whole y
                if (x[start] != y[start]) {
                    rtn.push_back(vector<int>{x[start], y[start], x[height]});
                }
                rtn.push_back(y);
                y_i++;
                x[start] = y[end];
            }
        }
    }
};
