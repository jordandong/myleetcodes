/*
Find the total number of patterns of the Android lock screen. The number of key used has to be at least 4, and max 9.

Example:
use 5 keys:
OAB
OOC
OED

OAB
OCD
OOE

Same thing goes with 4, 6, 7, 8, 9 keys. Count the total possible pattern. The order of keys used matters.

Rules:
At-least 4 and at-max 9 dots must be connected.
There can be no jumps
Once a dot is crossed, you can jump over it.

1 2 3         1 2 3        1 2 3        1 2 3
4 5 6         4 5 6        4 5 6        4 5 6
7 8 9         7 8 9        7 8 9        7 8 9
4-1-3-6 x     4-1-9-2 x    2-4-1-3-6 y  6-5-4-1-9-2 y
*/

// DP solution. T : O(2^9 * 9^2) , S : O(2^9 * 9)
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        // dp[i][j]: i is the set of the numbers in binary representation,
        // dp[i][j] is the number of ways ending with the number j.
        vector<vector<int>> dp(1 << 9 , vector<int>(9, 0));
        for (int i = 0; i < 9; ++i)
            dp[merge(0, i)][i] = 1;

        int res = 0;
        for (int used = 0; used < dp.size(); ++used) { //binary , x bit means x is used
            const auto number = number_of_keys(used);
            if (number > n)
                continue;

            for (int i = 0; i < 9; ++i) {
                if (!contain(used, i)) //last key number used
                    continue;

                if (m <= number && number <= n) {
                    res += dp[used][i];
                }

                const auto x1 = i / 3;
                const auto y1 = i % 3;
                for (int j = 0; j < 9; ++j) {
                    if (contain(used, j)) //current key shoule be not used before
                        continue;

                    const auto x2 = j / 3;
                    const auto y2 = j % 3;
                    if (((x1 == x2 && abs(y1 - y2) == 2) ||
                         (y1 == y2 && abs(x1 - x2) == 2) ||
                         (abs(x1 - x2) == 2 && abs(y1 - y2) == 2)) &&
                        !contain(used, convert((x1 + x2) / 2, (y1 + y2) / 2))) {
                            //exception cases, accross one key and that key is not used
                            continue;
                    }
                    dp[merge(used, j)][j] += dp[used][i]; //dp adding
                }
            }
        }
        return res;
    }

private:
    inline int merge(int i, int j) {
        return i | (1 << j);
    }

    inline int number_of_keys(int i) {
        int number = 0;
        for (; i; i &= i - 1) {
            ++number;
        }
        return number;
    }

    inline bool contain(int i, int j) {
        return i & (1 << j);
    }

    inline int convert(int i, int j) {
        return 3 * i + j;
    }
};

// T : O(9!) , S : O(1)
class Solution {
private:
    bool used[9];
    bool isValid(int index, int last) {		
        if (used[index])
            return false;
        if (last == -1)
            return true;				
        // knight moves and row/col adjcent, 1->0 or 1->2 or 1->4 or 1->6/8 ... 
        if ((index + last)%2 == 1)
            return true;
        int mid = (index +last)/2;
        //diagonals or row/col across 4, 0->8 or 1->7 ...
        if ( mid == 4)
            return used[4];
        // adajcent cells on diagonal, 0->4 or 5->7 ...
        if ((index%3 != last%3) && (index/3 != last/3)) {
            return true;
        }
        //all other adjacent cells, 0->2 or 0->6 ... 
        return used[mid];		
    }

    int calcPatterns(int last,int len) {
        if (len == 0) {
            return 1;				
        } else {
            int sum = 0;
            for (int i = 0; i < 9; i++) {									
                if (isValid(i, last)) {
                    used[i] = true;
                    sum += calcPatterns(i, len - 1);
                    used[i] = false;					
                }
            }
            return sum;
        }			
    }

public:
    int numberOfPatterns(int m, int n) {
        int res =0;
        for (int len = m; len <= n; len++) {				
            res += calcPatterns(-1, len);	
            for (int i = 0; i < 9; i++) {
                used[i] = false;					
            }
        }
        return res;
    }
};

int main() {
    Solution alp;
    cout<<alp.numberOfPatterns(4, 9)<<endl;
    return 0;
}

389112
