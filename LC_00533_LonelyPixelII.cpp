/*
Given a picture consisting of black and white pixels, and a positive integer N,
find the number of black pixels located at some specific row R and column C that align with all the following rules:
1. Row R and column C both contain exactly N black pixels.
2. For all rows that have a black pixel at column C, they should be exactly the same as row R

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
Example:
Input:                                            
[['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'W', 'B', 'W', 'B', 'W']] 
N = 3

Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index                                            
0    [['W', 'B', 'W', 'B', 'B', 'W'],    
1     ['W', 'B', 'W', 'B', 'B', 'W'],    
2     ['W', 'B', 'W', 'B', 'B', 'W'],    
3     ['W', 'W', 'B', 'W', 'B', 'W']]    
row index

Take 'B' at row R = 0 and column C = 1 as an example:
1. Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
2. Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.

Note:
The range of width and height of the input 2D array is [1,200].

Hide Tags Array Depth-first Search
*/

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m = picture.size();
        if (!m)
            return 0;
        int n = picture[0].size();
        if (!n)
            return 0;
        vector<int> rows(m, 0), cols(n, 0);
        unordered_map<string,int> mp;
        vector<string> rows_str;
        for (int i = 0; i < m; ++i) {
            string s;
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    rows[i]++;
                    cols[j]++;
                }
                s.push_back(picture[i][j]);
            }
            mp[s]++;
            rows_str.push_back(s);
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            if (rows[i] == N && mp[rows_str[i]] == N) {
                for (int j = 0; j < n; ++j) {
                     if (picture[i][j] == 'B' && cols[j] == N)
                        ++res;
                }
            }
        }
        return res;
    }
};
