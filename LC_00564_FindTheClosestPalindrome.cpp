/*
Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:
Input: "123"
Output: "121"

Note:
1. The input n is a positive integer represented by string, whose length will not exceed 18.
2. If there is a tie, return the smaller one as answer.

Hide Tags String
*/

class Solution {
public:
    string nearestPalindromic(string n) {
        string res = n;
        long long num = atoll(n.c_str());
        int N = n.length();
        if (N == 0)
            return res;
        if (N == 1) {
            res[0] = (n == "0") ? '1': res[0] - 1;
            return res;
        }
            
        vector<long long> candidates;
        int half_size = (N + 1)/2;
        string half = n.substr(0, half_size);
        string tmp, rev_tmp, candidate;
        
        candidates.push_back((long long)pow(10.0, N*1.0) + 1); //10000...00001
        candidates.push_back((long long)pow(10.0, (N - 1)*1.0) - 1); //999...999
        
        if (N % 2) {
            tmp = half.substr(0, half.length() - 1);
            rev_tmp = rev_str(tmp);
            candidate = tmp + half.substr(half_size - 1) + rev_tmp;
        
            candidates.push_back(atoll(candidate.c_str())); //same
            
            if (candidate[half_size - 1] != '9') {
                candidate[half_size - 1] += 1;
                candidates.push_back(atoll(candidate.c_str())); //bigger
                candidate[half_size - 1] -= 1;
            }
            
            if (candidate[half_size - 1] != '0') {
                candidate[half_size - 1] -= 1;
                candidates.push_back(atoll(candidate.c_str())); //smaller
            }
        
        } else {
            tmp = half;
            rev_tmp = rev_str(tmp);
            candidate = tmp + rev_tmp;
        
            candidates.push_back(atoll(candidate.c_str())); //same
            
            if (candidate[half_size - 1] != '9') {
                candidate[half_size - 1] += 1;
                candidate[half_size ] += 1;
                candidates.push_back(atoll(candidate.c_str())); //bigger
                candidate[half_size - 1] -= 1;
                candidate[half_size ] -= 1;
            }
                
            if (candidate[half_size - 1] != '0') {
                candidate[half_size - 1] -= 1;
                candidate[half_size] -= 1;
                candidates.push_back(atoll(candidate.c_str())); //smaller
            }
        }
        
        long long delta = num, mi = num;
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] != num) {
                long long diff = abs(candidates[i] - num);
                if (diff < delta || (diff == delta && candidates[i] < mi)) {
                    res = to_string(candidates[i]);
                    mi = candidates[i];
                    delta = diff;
                }
            }
        }
        return res;
    }
private:
    string rev_str(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};
