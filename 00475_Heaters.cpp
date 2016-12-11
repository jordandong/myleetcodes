/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
1. Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
2. Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
3. As long as a house is in the heaters' warm radius range, it can be warmed.
4. All the heaters follow your radius standard and the warm radius will the same.

Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.

Hide Tags Binary Search
*/

//T : O(NlogN + MlogM), S : O(1)
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        heaters.push_back(INT_MAX);
        heaters.push_back(INT_MIN);
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int j = 0, ans = 0, N = heaters.size();
        for (auto ho : houses) {
            while (j < N && heaters[j] <= ho) //find the closest heaters on right
                j++;
            ans = max((long long)ans, min((long long)ho - (long long)heaters[j - 1], (long long)heaters[j] - (long long)ho));
        }
        return ans;
    }
};

//T : O(NlogN + MlogN), S : O(1)
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        heaters.push_back(INT_MAX);
        heaters.push_back(INT_MIN);
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (auto ho : houses) {
            int idx = findRadiusBinarySearchHeater(heaters, ho);
            ans = max((long long)ans, min((long long)ho - (long long)heaters[idx - 1], (long long)heaters[idx] - (long long)ho));

        }
        return ans;
    }
private:
    int findRadiusBinarySearchHeater(vector<int>& heaters, int house) {
        int lo = 0, hi = heaters.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (house >= heaters[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
