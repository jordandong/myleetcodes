/*
Suppose you have a random list of people standing in a queue.
Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

Hide Tags Greedy
*/

// T : O(N*N) , S:O(1)
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), 
            [](const pair<int, int>& a, pair<int, int>& b) {
                return b.first == a.first ? a.second < b.second : b.first < a.first;
            });
        vector<pair<int, int>> result;
        for (const auto& p : people) {
            result.insert(result.begin() + p.second, p);
        }
        return result;
    }
};

// T : O(N*N) , S:O(N)
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int size = people.size();
        vector<pair<int, int>> res;
        vector<pair<int, int>> p_copy = people; 
        while (size--) {
            int min_h = INT_MAX, min_k = INT_MAX;
            for (int i = 0; i < p_copy.size(); i++) {
                if (p_copy[i].second == 0 && p_copy[i].first < min_h) {
                    min_h = p_copy[i].first;
                    min_k = p_copy[i].second;
                }
            }
        
            for (int i = 0; i < p_copy.size(); i++) {
                if (p_copy[i].first <= min_h) {
                    if (p_copy[i].first == min_h && p_copy[i].second == min_k)
                        res.push_back(people[i]);
                    p_copy[i].second--;
                }
            }
        }
        return res;
    }
};
