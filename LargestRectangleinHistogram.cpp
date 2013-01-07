//============================================================================
// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1, find the area of largest rectangle in the
// histogram.
//
// For example,
// Given height = [2,1,5,6,2,3],
// return 10.
//============================================================================

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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

int main() {
	return 0;
}



class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len = height.size();
        int x[len];
        int m=0;
        for(int j=0;j<len;j++)
            x[j]=1;
        
        for(int i=0;i<len;i++){
            for (int i1=i-1;i1>=0;i1--){
                if(height[i1]>=height[i])
                    x[i]+=1;
                else
                    break;
            }
            
            for (int i2=i+1;i2<len;i2++){
                if(height[i2]>=height[i])
                    x[i]+=1;
                else
                    break;
            }
        }
        
        for(int k=0;k<len;k++){
            int area = x[k]*height[k];
            if(area>=m)
                m=area;
        }
    
        return m;        
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int> &h) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> p;
        int i = 0, m = 0;
        h.push_back(0);
        while(i < h.size()) {
            if(p.empty() || h[p.top()] <= h[i])
                p.push(i++);
            else {
                int t = p.top();
                p.pop();
                m = max(m, h[t] * (p.empty() ? i : i - p.top() - 1 ));
            }
        }
        return m;
    }
};
