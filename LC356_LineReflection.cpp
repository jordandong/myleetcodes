/*
Problem Statement TBD
*/

//T : O(N), S : O(N)
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty())
            return true;

        unordered_map<int, unordered_set<int>> groups_by_y;
        int left = INT_MAX;
        int right = INT_MIN;
        for (const auto& p : points) {
            groups_by_y[p.second].emplace(p.first);
            left = min(left, p.first);
            right = max(right, p.first);
        }
        const auto mid = left + right;
        for (const auto& kvp : groups_by_y) {
            for (const auto& x : kvp.second) {
                if (kvp.second.count(mid - x) == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

//T : O(NlogN), S : O(1)
class Solution {
public:
    bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
    
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty())
            return true;
        sort(points.begin(), points.end());
        sort(points.begin(), points.begin() + distance(points.begin(), points.end()) / 2, cmp);
        const auto mid = points.front().first + points.back().first;
        for (int left = 0, right = points.size() - 1; left <= right; ++left, --right) {
            if ((mid != points[left].first + points[right].first) || 
                (points[left].first != points[right].first &&
                 points[left].second != points[right].second)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // your code goes here
	  vector<pair<int, int>> data = {{1,10}, {1, 15}, {2,20}, {9,20}, {10, 9}, {10, 15}};
	  Solution sol;
	  cout<<sol.isReflected(data)<<endl;
	  return 0;
}
