//============================================================================
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing all ones and return its area.
//============================================================================


//O(m*3n)
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rtn = 0;
        int m = matrix.size();
        if(!m)
            return rtn;
        int n = matrix[0].size();
        vector<int> h(n, 0);
        for(int i=0; i<m; i++){//O(m)
            for(int j=0; j<n; j++){//O(n)
                if(matrix[i][j]=='1'){
                    h[j]++;
                }else{
                    h[j]=0;
                }
            }
            rtn = max(rtn, largestRectHist(h, n)); //O(2*n)
        }
        return rtn;
    }
    
    int largestRectHist(vector<int> &h, int n){
        stack<int> stk;
        int rtn = 0;
        h.push_back(0);
        int i = 0;
        while(i<=n){
            if(stk.empty() || h[i] >= h[stk.top()]){
                stk.push(i++);
            }else{
                int j = stk.top();
                stk.pop();
                rtn = max(rtn, h[j]*(stk.empty()?i:(i - stk.top() - 1)));
            }
        }
        return rtn;
    }
};


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

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!matrix.size())
            return 0;
            
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int> > rec=vector<vector<int> >(M, vector<int>(N, 0));
        for (int j = 0; j < N; j++){
            for (int i = 0; i < M; i++){
                if (matrix[i][j]=='0')
                    rec[i][j] = 0;
                else
                    rec[i][j] = (i==0 ? 1 : 1 + rec[i-1][j]);
            }
        }


        int nMax = 0;
        for (int i = M-1; i >= 0; i--){
            for (int j = i; j >= 0; j--){
                int nLen = 0;
                int nBeg = -1;
                for (int k = 0; k < N; k++){
                    if ((rec[i][k]!=0) && (rec[j][k]!=0) && (rec[i][k]-rec[j][k] == i-j)){
                        if (nBeg < 0)
                            nBeg = k;
                        nLen = max(nLen, k - nBeg + 1);
                    }
                    else
                        nBeg = -1;
                }

                nMax = max(nMax, nLen*(i-j+1));
            }
        }

        return nMax;
    }
};


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
