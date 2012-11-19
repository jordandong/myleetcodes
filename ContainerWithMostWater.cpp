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
