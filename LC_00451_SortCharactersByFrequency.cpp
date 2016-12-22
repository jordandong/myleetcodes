/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"
Output:
"eert"
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input:
"cccaaa"
Output:
"cccaaa"
Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"
Output:
"bbAa"
Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

Hide Tags Hash Table Heap
*/

class Solution {
public:
    string frequencySort(string str) {
        string res = "";  
        vector<int> mp(256, 0);
        vector<pair<char, int> > arr;
        for (auto c : str)
            mp[c]++;
        for (int i = 0; i < 256; i++) {
            if (mp[i] != 0) {
                arr.push_back({i, mp[i]});
            }
        }
        sort(arr.begin(), arr.end(), 
             [](pair<char, int> &a, pair<char, int> &b) {
                if (a.second == b.second)
                    return a.first < b.first;
                return a.second > b.second;});
        for (auto &e : arr) {
            res.append(e.second, e.first); 
        }
        return res;
    }
};

class Solution {
public:
    string frequencySort(string str) {
        string res = "";
        vector<pair<char, int> > arr(256, {'#', 0});
        for (auto c : str) {
            arr[c].first = c;
            arr[c].second++;
        }
        sort(arr.begin(), arr.end(), 
             [](pair<char, int> &a, pair<char, int> &b) {
                if (a.second == b.second)
                    return a.first < b.first;
                return a.second > b.second;});
        for (auto &e : arr) {
            if (e.second != 0)
                res.append(e.second, e.first); 
        }
        return res;
    }
};
