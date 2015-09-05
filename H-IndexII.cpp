/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:
Expected runtime complexity is in O(log n) and the input is sorted.

Hide Tags Binary Search
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int lo = 0, hi = N - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (citations[mid] >= N - mid)
                hi--;
            else
                lo++;
        }
        return N - lo;
    }
};
