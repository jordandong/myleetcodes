/*
A group of two or more people wants to meet and minimize the total travel distance.
You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group.
The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):
1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

Hint:
Try to solve it in one dimension first. How can this solution apply to the two dimension case?
*/

//T : O(NlogN), S : O(M + N)
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m = 0)
          return 0;
        int n = grid[0].size();
        if (n == 0)
          return 0;
  
        vector<int> ii, jj;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ii.push_back(i); //i already sorted
                    jj.push_back(j);
                }
            }
        } 
        sort(jj.begin(), jj.end()); //sort j
        int c = ii.size(), s = 0;
        int io = ii[c/2]; //mid point
        int jo = jj[c/2];
        for (int i : ii)
            s += abs(i - io);
        for (int j : jj)
            s += abs(j - jo);
        return s;
    }
};

// T : O(N) , S : O(M + N)
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m = 0)
          return 0;
        int n = grid[0].size();
        if (n == 0)
          return 0;
        vector<int> x, y;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        //nth_element(x.begin(), x.begin() + x.size() / 2, x.end()); //x already sorted when filling
        nth_element(y.begin(), y.begin() + y.size() / 2, y.end());
        const int mid_x = x[x.size() / 2];
        const int mid_y = y[y.size() / 2];
        int sum = 0;
        for (int i : x)
            sum += abs(i - mid_x);
        for (int j : y)
            sum += abs(j - mid_y);
        return sum;
    }
};
