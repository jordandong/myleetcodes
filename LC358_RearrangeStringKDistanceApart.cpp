/*
TBD
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class cmp {
public:
    bool operator() (const pair<char, int> &a, const pair<char, int> &b) const {
        return a.second < b.second;
    }
};

string rearrange(int k, string s) {
    string res = s;
    priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> q;
    char mp[256] = {0};
    for(int i = 0; i < res.length(); i++) {
        mp[res[i]]++;
    }
    for(int i = 0; i < 256; i++) {
        if (mp[i] > 0)
            q.push({i, mp[i]});
    }

    if (k*(q.top().second - 1) + 1 > res.length())
        return "invalid input";

    int start = 0, round = 0;
    while (!q.empty()) {
        auto e = q.top();
        q.pop();
        while (e.second > 0) {
            if (start + k*round >= res.length()) {
                start++;
                round = 0;
            }
            res[start + round*k] = e.first;
            e.second--;
            round++;
        }
    }
    return res;
}

int main() {
    for (int i = 1; i < 8; i++) {
        cout<<rearrange(i, "aaaaabbbbccccdddd")<<endl;
    }
    return 0;
}

aaaaabbbbddddcccc
adadadadacbcbcbcb
abdabcabcadcadcbd
abdcabdcabdcabdca
invalid input
invalid input
invalid input
