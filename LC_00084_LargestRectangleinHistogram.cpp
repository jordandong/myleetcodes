/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

Hide Tags Array Stack
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &h) {
        stack<int> p;
        int i = 0, m = 0;
        h.push_back(0);
        while(i < h.size()) {
            if(p.empty() || h[p.top()] <= h[i]){
                p.push(i++);
            }else {
                int t = p.top();
                p.pop();
                m = max(m, h[t] * (p.empty() ? i : i - p.top() - 1 ));
            }
        }
        return m;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    	int n = height.size();
    	int y[n];
    	stack<int> stk;
    	for (int i = 0; i < n; i++) {
    	    while (!stk.empty()) {
    	    	if (height[i] <= height[stk.top()])
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
    	    	if (height[i] <= height[stk.top()])
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
    	    y[i] = height[i] * (y[i] + 1);
    	    if (y[i] > res)
    	        res = y[i];
    	}
    	return res;
    }
};
