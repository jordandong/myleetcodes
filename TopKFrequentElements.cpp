/*
Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

Hide Tags Hash Table Heap
Hide Similar Problems (M) Word Frequency (M) Kth Largest Element in an Array
*/

//T : O(3*N), S : O(2*N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto &e : nums)
            mp[e]++;

        vector<vector<int> > buckets(nums.size() + 1); 
        for (auto p : mp)
            buckets[p.second].push_back(p.first);

        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0 && res.size() < k; --i) {
            for (auto &num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k)
                    break;
            }
        }
        return res;
    }
};

//T : O(N + N*log(N - K)), S : O(N + N -K)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto & e : nums){
            mp[e]++;
        }

        vector<int> res;
        priority_queue<pair<int,int> > q; //maxHeap
        for(auto e : mp) {
            q.push(make_pair(e.second, e.first));
            if(q.size() > mp.size() - k) {
                res.push_back(q.top().second);
                q.pop();
            }
        }
        return res;
    }
};
