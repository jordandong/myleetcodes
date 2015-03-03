/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.

Hide Tags Sort
*/

/*
Suppose there are N elements and they range from A to B.

Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)]

Let the length of a bucket to be len = ceiling[(B - A) / (N - 1)], then we will have at most num = (B - A) / len + 1 of bucket

for any number K in the array, we can easily find out which bucket it belongs by calculating loc = (K - A) / len and therefore maintain the maximum and minimum elements in each bucket.

Since the maximum difference between elements in the same buckets will be at most len - 1, so the final answer will not be taken from two elements in the same buckets.

For each non-empty buckets p, find the next non-empty buckets q, then q.min - p.max could be the potential answer to the question. Return the maximum of all those values.
*/
class Solution {
public:
    int maximumGap(vector<int> &num) {
        int sz = num.size();  
        if(sz < 2)  
            return 0;

        int mx = num[0];
        int mi = num[0];
        int delta = 0;
        for(int i = 1; i < sz; i++){
            mx = max(mx, num[i]);
            mi = min(mi, num[i]);
        }
        delta = ceil(double(mx - mi)/(sz - 1));
        int bin_sz = (mx - mi)/delta + 1;
        vector<int> mx_bin(bin_sz, -1);
        vector<int> mi_bin(bin_sz, -1);
        
        for(int i = 0; i < sz; i++){
            int bin = (num[i] - mi)/delta;
            if(mi_bin[bin] == -1){
                mi_bin[bin] = num[i];
            }else{
                mi_bin[bin] = min(mi_bin[bin], num[i]);
            }
            
            if(mx_bin[bin] == -1){
                mx_bin[bin] = num[i];
            }else{
                mx_bin[bin] = max(mx_bin[bin], num[i]);
            }
        }
        
        int res = 0;
        int last_mx = mx_bin[0];
        for(int i = 0; i < bin_sz; i++){
            if(mi_bin[i] == -1)
                continue;
            if(mi_bin[i] - last_mx >= res){
                res = mi_bin[i] - last_mx;
            }
            last_mx = mx_bin[i];
        }
        return res;  
    }
};

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int sz = num.size();
        if(sz < 2)  
            return 0;  
        sort(num.begin(),num.end());  
        int mx = num[1] - num[0];  
        for(int i = 2; i < sz; i++){
            mx = max(num[i] - num[i-1], mx);  
        }  
        return mx;  
    }
};
