//============================================================================
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing all ones and return its area.
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int M = matrix.size();
        if (M == 0)
			return 0;
        int N = matrix[0].size();
        if (N == 0)
			return 0;
        int h[N];
        memset(h, 0, sizeof(int)*N);
        int res = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == '1')
					h[j]++;
                else
					h[j] = 0;
            }
            res = max(res, largestRectangleinHistogram2(h, N));
        }
        return res;
    }

    int largestRectangleinHistogram2(int x[], int n) {
        int y[n];
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty()) {
                if (x[i] <= x[stk.top()])
					stk.pop();
                else
					break;
            }
            int j = (stk.empty()) ? -1 : stk.top();
            // Calculating number of bars on the left
            y[i] = i - j - 1;
            stk.push(i);
        }

        while (!stk.empty())
			stk.pop();

        for (int i = n - 1; i > 0; i--) {
            while (!stk.empty()) {
                if (x[i] <= x[stk.top()])
					stk.pop();
                else
					break;
            }
            int j = (stk.empty()) ? n : stk.top();
            // Calculating number of bars on the left + right
            y[i] += (j - i - 1);
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            // Calculating height * width
            y[i] = x[i] * (y[i] + 1);
            if (y[i] > res)
				res = y[i];
        }
        return res;
    };
};

int main() {
    return 0;
}


class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int n = matrix[0].size();
        vector<int> H(n);
        vector<int> L(n);
        vector<int> R(n, n);

        int ret = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            int left = 0, right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j];	//keep the height at right bottom i,j
                    L[j] = max(L[j], left);	//keep the satrt left pos with '1'
                }
                else {
                    left = j+1;
                    H[j] = 0; L[j] = 0; R[j] = n;
                }
            }
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {	//keep the end right pos with '1' at right bottom i,j
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j]*(R[j]-L[j]));
                }
                else {
                    right = j;
                }
            }
        }

        return ret;
    }
};
