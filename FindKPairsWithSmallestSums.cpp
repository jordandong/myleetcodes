/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u,v) which consists of one element from the first array and one element from the second array.
Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
Return: [1,2],[1,4],[1,6]
The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
Return: [1,1],[1,1]
The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 
Return: [1,3],[2,3]
All possible pairs are returned from the sequence:
[1,3],[2,3]

Credits:
Special thanks to @elmirap and @StefanPochmann for adding this problem and creating all test cases.

Hide Tags Heap
*/

/*
  1  2  3  4  5
1 2  3  4  5  6
2 3  4  5  6  7
3 4  5  6  7  8
4 5  6  7  8  9
5 6  7  8  9  10
*/

// T : O(k*log(min(M, N, k))), S : O(min(M, N, k))
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.size() > nums2.size()) {
            auto rtn = kSmallestPairs(nums2, nums1, k);
            for (auto &pair : rtn) {
                swap(pair.first, pair.second);
            }
            return rtn;
        }

        vector<pair<int, int>> pairs;
        using P = pair<int, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> q;
        auto push = [&nums1, &nums2, &q](int i, int j) {
            if (i < nums1.size() && j < nums2.size()) {
                q.emplace(nums1[i] + nums2[j], make_pair(i, j));
            }
        };

        push(0, 0);
        while (!q.empty() && pairs.size() < k) {
            auto tmp = q.top();
            q.pop();
            int i, j;
            tie(i, j) = tmp.second;
            pairs.emplace_back(nums1[i], nums2[j]);
            push(i, j + 1); //update in the same row
            if (j == 0) {
                push(i + 1, 0);  //update the first pair in the next row
            }
        }
        return pairs; 
    }
};

//T : O(k*min(M,N)), S : O(min(M, N))
class Solution {
public:
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        if (m > n) {
            auto rtn = kSmallestPairs(nums2, nums1, k);
            for (auto &e : rtn) {
                swap(e.first, e.second);
            }
            return rtn;
        }

        vector<pair<int, int>> res;
        k = min(k, m * n);
        vector<int> indice(m, 0);
        while(k-- > 0){
            int tmp_index = 0;
            long tmp_sum = LONG_MAX;
            for(int i = 0; i < m; i++){
                if(indice[i] < n && tmp_sum >= nums1[i] + nums2[indice[i]]){
                    tmp_index = i;
                    tmp_sum = nums1[i] + nums2[indice[i]];
                }
            }
            res.push_back(make_pair(nums1[tmp_index], nums2[indice[tmp_index]]));
            indice[tmp_index]++;
        }
        return res;
    }
};
