/*
Given a picture consisting of black and white pixels, find the number of black lonely pixels.
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

Example:
Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]
Output: 3
Explanation: All the three 'B's are black lonely pixels.

Note:
The range of width and height of the input 2D array is [1,500].

Hide Tags Array Depth-first Search
*/

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int M = picture.size();
        if (M == 0)
            return 0;
        int N = picture[0].size();
        if (N == 0)
            return 0;
        int res = 0;
        vector<int> row(M, 0), col(N, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (picture[i][j] == 'B') {
                    ++row[i];
                    ++col[j];
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            if (row[i] == 1) {
                for (int j = 0; j < N; ++j)
                    if (picture[i][j] == 'B' && col[j] == 1)
                        res++;
            }
        }
        return res;
    }
};
