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
        return getSkylineHelper(buildings, 0, N - 1);
    }
    
    // Divide
    vector<pair<int, int> > getSkylineHelper(vector<vector<int>>& buildings, int l, int r) {
        if (l == r)
            return vector<pair<int, int> > { make_pair(buildings[l][start], buildings[l][height]),
                                             make_pair(buildings[l][end], 0) };
        int mid = l + (r - l) / 2;
        auto l_rtn = getSkylineHelper(buildings, l, mid);
        auto r_rtn = getSkylineHelper(buildings, mid + 1, r);
        return getSkylineMerge(l_rtn, r_rtn);
    }
    
    // Merge
    vector<pair<int, int> > getSkylineMerge(vector<pair<int, int> > &l_rtn, vector<pair<int, int> > &r_rtn) {
        vector<pair<int, int> > rtn;
        int i = 0, j = 0;
        int hl = -1, hr = -1, mh = -1;
        
        while (i < l_rtn.size() && j < r_rtn.size()) {
            if (l_rtn[i].first < r_rtn[j].first) {
                hl = l_rtn[i].second;
                mh = max(hl, hr);
                if (rtn.empty() || rtn.back().second != mh)
                    rtn.push_back(make_pair(l_rtn[i].first, mh));	
                i++;
            } else if (l_rtn[i].first > r_rtn[j].first) {
                hr = r_rtn[j].second;
                mh = max(hl, hr);
                if (rtn.empty() || rtn.back().second != mh)
                    rtn.push_back(make_pair(r_rtn[j].first, mh));	
                j++;
            } else {
                hl = l_rtn[i].second;
                hr = r_rtn[j].second;
                mh = max(hl, hr);
                if (rtn.empty() || rtn.back().second != mh)
                    rtn.push_back(make_pair(l_rtn[i].first, mh));
                i++;
                j++;
            }
        }

        // remaining l/r_rtn
        if(i < l_rtn.size())
            rtn.insert(rtn.end(), l_rtn.begin() + i, l_rtn.end());
        if(j < r_rtn.size())
            rtn.insert(rtn.end(), r_rtn.begin() + j, r_rtn.end());
        return rtn;
    }
};

//Similar to swipe line
class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        map<int, vector<int> > starts;
        map<int, vector<int> > ends;
        set<int> points;

        for(int i = 0; i < buildings.size(); ++i) {
            starts[buildings[i][0]].push_back(buildings[i][2]);
            ends[buildings[i][1]].push_back(buildings[i][2]);
            points.insert(buildings[i][0]);
            points.insert(buildings[i][1]);
        }

        vector<pair<int, int> > res;
        pair<int, int> tResult;
        map<int, int> tree;
        int currMax = -1;
        int currStart = -1;

        for(set<int>::iterator iter = points.begin(); iter != points.end(); ++iter) {//BST increasing order
            vector<int> start = starts[*iter];
            vector<int> end = ends[*iter];

            //begin and end with same height are cancelled
            for(int i = 0; i < start.size(); ++i) {
                tree[start[i]]++;
            }

            for(int i = 0; i < end.size(); ++i) {
                tree[end[i]]--;
                if(tree[end[i]] == 0) {
                    tree.erase(end[i]);
                }
            }

            if (tree.size() == 0){
                tResult.first = *iter;
                tResult.second = 0;
                res.push_back(tResult);

                currStart = -1;
                currMax = -1;

            } else {
                if(currMax == -1) {
                    currStart = *iter;
                    currMax = tree.rbegin()->first;

                    tResult.first = currStart;
                    tResult.second = currMax;
                    res.push_back(tResult);
                } else {
                    int max = tree.rbegin()->first;
                    if(max != currMax) {
                        currStart = *iter;
                        currMax = max;
                        tResult.first = currStart;
                        tResult.second = currMax;
                        res.push_back(tResult);
                    }
                }
            }
        }
        return res;
    }
};
