/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel.
The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically.
Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:
[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
*/

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        if (m == 0)
            return 0;
        int n = image[0].size();
        if (n == 0)
            return 0;

        int u = search(image,     0, x, 0, n,  true,  true);
        int d = search(image, x + 1, m, 0, n, false,  true);
        int l = search(image,     0, y, u, d,  true, false);
        int r = search(image, y + 1, n, u, d, false, false);
        return (r - l) * (d - u);
    }
private:
    bool white(vector<vector<char>>& image, int mid, int k, int row) {
        return (row ? image[mid][k] : image[k][mid]) == '0'; 
    }
    int search(vector<vector<char>>& image, int b, int e, int mini, int maxi, bool first, bool row) {
        while (b != e) {
            int mid = (b + e) / 2;
            int k = mini;
            while (k < maxi && white(image, mid, k, row))
                k++;
            if (k < maxi == first)
                e = mid;
            else
                b = mid + 1;
        }
        return b;
    }
};
