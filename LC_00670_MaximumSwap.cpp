/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number.
Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:
Input: 9973
Output: 9973
Explanation: No swap.

Note:
1. The given number is in the range [0, 10^8]
*/

// T : O(N) , S : O(N)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int N = s.length();
        if (N == 0)
            return num;
        char t_mx = s[N - 1];
        int t_max_id = N - 1, max_id = N - 1, min_id = N - 1;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] > t_mx) {
                t_mx = s[i];
                t_max_id = i;
            } else if (s[i] < t_mx) {
                min_id = i;
                max_id = t_max_id;
            }
        }
        
        if (max_id > min_id)
            swap(s[max_id], s[min_id]);
        return stoi(s);
    }
};

// T : O(N) , S : O(N)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int N = s.length();
        if (N == 0)
            return num;
        int i = 0;
        //find the first element bigger than the previous one
        for (i = 1; i < N; i++) {
            if (s[i] > s[i - 1])
                break;
        }
        if (i == N)
            return num;

        //find the max element after the element found in last step
        char mx = s[i];
        int idx = i;
        for (int j = i; j < N; j++) {
            if (s[j] >= mx) {
                idx = j;
                mx = s[j];
            }
        }
        //find the first element smaller than the element found in last step and swap
        for (int j = 0; j < i; j++) {
            if (s[j] < s[idx]) {
                swap(s[j], s[idx]);
                return stoi(s);
            }
                
        }
        return num;
    }
};

//T : O(NlogN) , S : O(N)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string r = s;
        sort(r.begin(), r.end());
        reverse(r.begin(), r.end());
        
        for ( int i = 0; i < s.size(); ++i) {
            if (s[i] != r[i]) {
                char mx = s[i];
                int idx = i;
                for (int j = i; j < s.size(); j++) {
                    if (s[j] >= mx) { //the last biggest one
                        mx = s[j];
                        idx = j;
                    }
                }
                swap(s[i], s[idx]);
                return stoi(s);
            }
        }
        return num;
    }
};

//T : O(N^2) , S : O(N)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for ( int i = 0; i < s.size(); ++i) {
            for ( int j = i + 1; j < s.size(); ++j ) {
                swap(s[i], s[j]);
                num = max(num, stoi(s));
                swap(s[i], s[j]);
            }
        }
        return num;   
    }
};
