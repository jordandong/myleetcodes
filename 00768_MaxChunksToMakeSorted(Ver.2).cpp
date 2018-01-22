/*
This question is the same as "Max Chunks to Make Sorted (ver. 1)" except the integers of the given array are not necessarily distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 2000].
arr[i] will be an integer in range [0, 10**8].
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> max_l(n, arr[0]), min_r(n, arr[n - 1]);

        for (int i = 1; i < n; i++)
            max_l[i] = max(max_l[i - 1], arr[i]);

        for (int i = n - 2; i >= 0; i--)
            min_r[i] = min(min_r[i + 1], arr[i]);

        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (max_l[i] <= min_r[i + 1])
                res++;
        }
        return res + 1;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int, int>> arr_id;
        for (int i = 0; i < arr.size(); i++)
            arr_id.push_back({arr[i], i});
        sort(arr_id.begin(), arr_id.end());
        int mx = 0, ans = 0;
        for (int i = 0; i < arr_id.size(); i++) {
            mx = max(mx, arr_id[i].second);
            if (mx == i)
                ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        multiset<int> cur, expect;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < arr.size(); i++) {
            expect.insert(sorted[i]);
            cur.insert(arr[i]);
            if (cur == expect)
                chunks++;
        }
        return chunks;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> expect = arr;
        sort(expect.begin(), expect.end());
        int ans = 0, mx = -1, dup = 0, exp_dup = 0;
        for (int i = 0; i < n; ++i) {
            if (i && expect[i] == expect[i - 1])
                exp_dup++;
            else
                exp_dup = 0;

            if (arr[i] > mx) {
                mx = arr[i];
                dup = 0;
            } else if (arr[i] == mx) {
                dup++;
            }

            if (expect[i] == mx && exp_dup == dup)
                ans++;
        }
        return ans;
    }
};
