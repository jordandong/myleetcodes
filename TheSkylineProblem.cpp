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

//Similar to swipe line, using BST instead of PriorityQueue since delete edge is easy in BST
//T:O(NlogN) S:O(N)
class Solution {
public:
    enum {
        start,
        end,
        height
    };
    
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        int curr_max = 0;
        vector<pair<int, int>> res;
        map<int, int> count; // <height, ref_cnt>. map is a BST internally. Query/Insert/Delete O(logN)
        map<int, vector<pair<int, bool> > > edges; //< pos, <height, start> >
        for (auto& building : buildings) { //O(NlogN) build BST
            edges[building[start]].push_back(make_pair(building[height], true));
            edges[building[end]].push_back(make_pair(building[height], false));
        }

        for (auto& e : edges) { //sorted order. O(1), each of 2N
            auto& pos = e.first;
            auto& heights = e.second;

            for (auto& h : heights) { //O(logN) 
                if (h.second) //start, add
                    ++count[h.first];
                else if(--count[h.first] == 0) //end, remove
                    count.erase(h.first); //same height, cancelled
            }

            if (count.empty() || curr_max != count.crbegin()->first) { //end pos OR new start pos
                curr_max = count.empty() ? 0 : count.crbegin()->first; //highest height
                res.push_back(make_pair(pos, curr_max));
            }
        }
        return res;
    }
};
