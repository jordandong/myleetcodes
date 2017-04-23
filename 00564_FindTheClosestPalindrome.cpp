/*
Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:
Input: "123"
Output: "121"
Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.
*/

class Solution {
public:
    string nearestPalindromic(string n) {
        string res = n;
        int N = n.length();
        if (N == 0)
            return "";
        if (N == 1) {
            if (n == "0") {
                res = "1";
            } else {
                res[0] -= 1;
            }
            return res;
        }
            
            
        vector<long long> cand;
        long long num = atoll(n.c_str());
        cand.push_back((long long)pow(10.0, N*1.0) + 1);
        cand.push_back((long long)pow(10.0, (N - 1)*1.0) - 1);
        string half = res.substr(0, (N + 1)/2);
        string tmp;
        if (N % 2) {
            tmp = half.substr(0, half.length() - 1);
            string c;
            if (half.back() != '0') {
               c = tmp + to_string(half.back() - '0' - 1) + rev_str(tmp);
               cand.push_back(atoll(c.c_str()));
            }
            
            tmp = half.substr(0, half.length() - 1);
            c = tmp + to_string(half.back() - '0' + 1) + rev_str(tmp);
            cand.push_back(atoll(c.c_str()));
            
            tmp = half.substr(0, half.length() - 1);
            c = tmp + to_string(half.back() - '0') + rev_str(tmp);
            cand.push_back(atoll(c.c_str()));
        } else {
            tmp = half;
            string c;
            if (tmp.back() != '0') {
               tmp.back() = tmp.back() - 1;
               c = tmp + rev_str(tmp);
               cand.push_back(atoll(c.c_str()));
            }
            
            tmp = half;
            tmp.back() = tmp.back() + 1;
            c = tmp + rev_str(tmp);
            cand.push_back(atoll(c.c_str()));
            
            tmp = half;
            tmp.back() = tmp.back();
            c = tmp + rev_str(tmp);
            cand.push_back(atoll(c.c_str()));
        }
        
        long long delta = num;
        long long mi = num;
        for (int i = 0; i < cand.size(); i++) {
            if (cand[i] != num) {
                if (abs(cand[i] - num) < delta) {
                    res = to_string(cand[i]);
                    mi = cand[i];
                    delta = abs(cand[i] - num);
                } else if (abs(cand[i] - num) == delta && cand[i] < mi) {
                    res = to_string(cand[i]);
                    mi = cand[i];
                }
            }
            cout<<cand[i]<<endl;
        }
        return res;
    }
private:
    string rev_str(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};
