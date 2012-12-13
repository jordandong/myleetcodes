//============================================================================
// Given n non-negative integers a1, a2, ..., an, where each represents a
// point at coordinate (i, ai). n vertical lines are drawn such that the two
// endpoints of line i is at (i, ai) and (i, 0). Find two lines, which
// together with x-axis forms a container, such that the container contains
// the most water.
//
// Note: You may not slant the container.
//============================================================================

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int max = 0;
        while (i < j) {
            int h = (height[i] < height[j]) ? height[i] : height[j];
            int res = h * (j - i);
            if (res > max)
            	max = res;
            if (height[i] <= height[j]) {
                i++;
                while (height[i] < h && i < j)
                	i++;
            }
            else {
                j--;
                while (height[j] < h && i < j)
                	j--;
            }
        }
        return max;
    }
};

int main() {
    return 0;
}



class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return doMax(height, 0, height.size()-1);
    }
    
    int doMax(vector<int> &height, int l0, int r0) {
        int l=l0;
        int r=r0;
        int currMax = (r-l)*min(height[l],height[r]);
        int lMax=0, rMax=0;
 
        if(height[l]>height[r]) { //save l, inspect r-1
            int rr = r;
            while(--rr>l){
                if(height[rr]>height[rr+1])
                    break;
            }
            if(rr==l)
                rMax = currMax;
            else
                rMax = doMax(height, l, rr);
        }
        else if (height[l]<height[r]){// save r, inspect l+1
            int ll = l;
            while(++ll<r){
                if(height[ll]>height[ll-1])
                    break;
            }
            if(ll==r)
                lMax = currMax;
            else
                lMax = doMax(height, ll, r);
        }
        else{
            int ll = l;
            while(++ll<r){
                if(height[ll]>height[ll-1])
                    break;
            }
            if(ll==r){
                rMax = currMax;
                lMax = currMax;
            }
            else{
                lMax = doMax(height, ll, r);
                rMax = doMax(height, l, ll);
            }
        }
        return max(currMax,max(rMax,lMax));
    }
};
