/*
There is a ball in a maze with empty spaces and walls.
The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall.
When the ball stops, it could choose the next direction.
There is also a hole in this maze.
The ball will drop into the hole if it rolls on to the hole.

Given the ball position, the hole position and the maze, your job is to find out how the ball could drop into the hole by moving shortest distance in the maze.
The distance is defined by the number of empty spaces the ball go through from the start position (exclude) to the hole (include).
Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there may have several different shortest ways, you should output the lexicographically smallest way.
If the ball cannot reach the hole, output "impossible".

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space.
You may assume that the borders of the maze are all walls.
The ball and hole coordinates are represented by row and column indexes.

Example 1
Input 1: a maze represented by a 2D array
0 h 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 b 0
Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (0, 1)

Output: "lul"
Explanation:
There are two shortest ways for the ball to drop into the hole.
The first way is left -> up -> left, represented by "lul".
The second way is up -> left, represented by 'ul'.
Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'.
So the output is "lul".

Example 2
Input 1: a maze represented by a 2D array
0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
h 1 0 0 1
0 1 0 b 0
Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (3, 0)
Output: "impossible"
Explanation: The ball cannot reach the hole.

Note:
1. There are only one ball and one hole in the maze.
2. The ball and hole will only exist in the empty space, and they will not at the same position initially.
3. The given maze doesn't contain border (like the red rectangle in the example pictures), but you should assume the border of the maze are all walls.
4. The maze contains at least 2 empty spaces, and the length and width of the maze won't exceed 30.
*/

class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    string directions[4] = {"d", "u", "l", "r"};
    struct cmp{
        bool operator() (const pair<int,int> &p1, const pair<int,int> &p2){
            return p1.second > p2.second;
        }
    };
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> Dis(m, vector<int>(n, INT_MAX));
        vector<vector<string>> Way(m, vector<string>(n, ""));
        Dis[ball[0]][ball[1]] = 0;
        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> PQu;    //first: pos, second dist
        PQu.push({ball[0]*n + ball[1], 0});
        while (!PQu.empty()){
            auto start = PQu.top();
            PQu.pop();
            int x0 = start.first / n, y0 = start.first % n;
            if (start.second > Dis[x0][y0])
                continue;
            if (x0 == hole[0] && y0 == hole[1])
                return Way[x0][y0];
            for (int t = 0; t < 4; t++) {
                int xnew =x0, ynew = y0, move=0;
                string trys = Way[x0][y0] + directions[t];
                while (xnew + dx[t] >= 0 && xnew + dx[t] < m &&
                       ynew + dy[t] >= 0 && ynew + dy[t] < n &&
                       maze[xnew + dx[t]][ynew + dy[t]] == 0) {
                    xnew += dx[t];
                    ynew += dy[t];
                    move++;
                    if (xnew == hole[0] && ynew == hole[1])
                        break;
                }
                if (move == 0)
                    continue;
                if (Dis[x0][y0] + move < Dis[xnew][ynew]) {
                    Dis[xnew][ynew] = Dis[x0][y0] + move;
                    Way[xnew][ynew] = trys;
                    PQu.push({xnew * n + ynew, Dis[xnew][ynew]});
                } else if (Dis[x0][y0] + move == Dis[xnew][ynew]){
                    if (trys < Way[xnew][ynew])
                        Way[xnew][ynew] = trys;
                }
            }
        }
        return "impossible";
    }
};
