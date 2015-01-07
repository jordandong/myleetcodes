/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2(K)   -3     3
-5      -10    1
10      30    -5 (P)

Notes:
The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

/*
At first glance, this problem bears a large resemblance to the "Maximum/Minimum Path Sum" problem. However, a path with maximum overall health gain does not guarantee the minimum initial health, since it is essential in the current problem that the health never drops to zero or below. For instance, consider the following two paths: 0 -> -300 -> 310 -> 0 and 0 -> -1 -> 2 -> 0. The net health gain along these paths are -300 + 310 = 10 and -1 + 2 = 1, respectively. The first path has the greater net gain, but it requires the initial health to be at least 301 in order to balance out the -300 loss in the second room, whereas the second path only requires an initial health of 2.

Fortunately, this problem can be solved through a table-filling Dynamic Programming technique, similar to other "grid walking" problems:

To begin with, we should maintain a 2D array D of the same size as the dungeon, where D[i][j] represents the minimum health that guarantees the survival of the knight for the rest of his quest BEFORE entering room(i, j). Obviously D[0][0] is the final answer we are after. Hence, for this problem, we need to fill the table from the bottom right corner to left top.

Then, let us decide what the health should be at least when leaving room (i, j). There are only two paths to choose from at this point: (i+1, j) and (i, j+1). Of course we will choose the room that has the smaller D value, or in other words, the knight can finish the rest of his journey with a smaller initial health. Therefore we have:

  min_HP_on_exit = min(D[i+1][j], D[i][j+1])
Now D[i][j] can be computed from dungeon[i][j] and min_HP_on_exit based on one of the following situations:

If dungeon[i][j] == 0, then nothing happens in this room; the knight can leave the room with the same health he enters the room with, i.e. D[i][j] = min_HP_on_exit.
If dungeon[i][j] < 0, then the knight must have a health greater than min_HP_on_exit before entering (i, j) in order to compensate for the health lost in this room. The minimum amount of compensation is "-dungeon[i][j]", so we have D[i][j] = min_HP_on_exit - dungeon[i][j].
If dungeon[i][j] > 0, then the knight could enter (i, j) with a health as little as min_HP_on_exit - dungeon[i][j], since he could gain "dungeon[i][j]" health in this room. However, the value of min_HP_on_exit - dungeon[i][j] might drop to 0 or below in this situation. When this happens, we must clip the value to 1 in order to make sure D[i][j] stays positive: D[i][j] = max(min_HP_on_exit - dungeon[i][j], 1).
Notice that the equation for dungeon[i][j] > 0 actually covers the other two situations. We can thus describe all three situations with one common equation, i.e.:

D[i][j] = max(min_HP_on_exit - dungeon[i][j], 1)
for any value of dungeon[i][j].

Take D[0][0] and we are good to go. Also, like many other "table-filling" problems, the 2D array D can be replaced with a 1D "rolling" array here.
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        if(m == 0)
            return -1;
        int n = dungeon[0].size();
        if(n == 0)
            return -1;
            
        int c = 0;
        int min_h[2][n];
        min_h[c][n-1] = convert(1 - dungeon[m-1][n-1]);
        
        for(int j = n-2; j >= 0; j--)
            min_h[c][j] = convert(min_h[c][j+1] - dungeon[m-1][j]);
        
        for(int i = m-2; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(j == n-1)
                    min_h[c^1][j] = convert(min_h[c][j] - dungeon[i][j]);
                else
                    min_h[c^1][j] = convert(min(min_h[c][j], min_h[c^1][j+1]) - dungeon[i][j]);
            }
            c^=1;
        }
        return min_h[c][0];
    }
    
    int convert(int x){
        return x<=0?1:x;
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        if(m == 0)
            return -1;
        int n = dungeon[0].size();
        if(n == 0)
            return -1;
        
        int min_h[m][n]; //min_h means at(i, j), need min x points health to pass
        min_h[m-1][n-1] = convert(1 - dungeon[m-1][n-1]);
        
        for(int i = m-2; i >= 0; i--)
            min_h[i][n-1] = convert(min_h[i+1][n-1] - dungeon[i][n-1]);
        
        for(int j = n-2; j >= 0; j--)
            min_h[m-1][j] = convert(min_h[m-1][j+1] - dungeon[m-1][j]);
        
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                min_h[i][j] = convert(min(min_h[i+1][j], min_h[i][j+1]) - dungeon[i][j]);
            }
        }
        return min_h[0][0];
    }
    
    int convert(int x){
        return x<=0?1:x;
    }
};
