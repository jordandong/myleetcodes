/*
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

Example:
Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]
Return 4.

The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
After the rain, water are trapped between the blocks. The total volume of water trapped is 4.

Hide Tags Breadth-first Search Heap
*/

/*
For every point on the border set the water level to the point height
For every point not on the border set the water level to infinity
Put every point on the border into the set of active points
While the set of active points is not empty:
    Select the active point P with minimum level
    Remove P from the set of active points
    For every point Q adjacent to P:
        Level(Q) = max(Height(Q), min(Level(Q), Level(P)))
        If Level(Q) was changed:
            Add Q to the set of active points
Similar to D-J Algo
*/

struct lv_pts{
    int x;
    int y;
    int lv;
};

class cmp{
public:    
    bool operator() (const lv_pts &lp1, const lv_pts &lp2) {
        return lp1.lv > lp2.lv;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if(m == 0)
            return 0;
        int n = heightMap[0].size();
        if(n == 0)
            return 0;
        priority_queue<lv_pts, vector<lv_pts>, cmp> q;
        vector<vector<int> > lv = heightMap;
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    lv_pts p;
                    p.x = i;
                    p.y = j;
                    p.lv = heightMap[i][j];
                    q.push(p);
                }else{
                    lv[i][j] = INT_MAX;
                }
            }
        }
        
        while(q.size()){
            lv_pts c = q.top();
            q.pop();
            res += (c.lv - heightMap[c.x][c.y]);
            if(c.x - 1 >= 0)
                check_adj(c.x - 1, c.y, c.lv, q, lv, heightMap);
            if(c.x + 1 < m)
                check_adj(c.x + 1, c.y, c.lv, q, lv, heightMap);
            if(c.y - 1 >= 0)
                check_adj(c.x, c.y - 1, c.lv, q, lv, heightMap);
            if(c.y + 1 < n)
                check_adj(c.x, c.y + 1, c.lv, q, lv, heightMap);
        }
        return res;
    }
    
    void check_adj(int x, int y, int lv, priority_queue<lv_pts, vector<lv_pts>, cmp> &q, vector<vector<int> > &v, vector<vector<int> > &h){
        int t = max(min(lv, v[x][y]), h[x][y]);
        if(t != v[x][y]){
            v[x][y] = t;
            lv_pts pts;
            pts.x = x;
            pts.y = y;
            pts.lv = t;
            q.push(pts);
        }
    }
};
