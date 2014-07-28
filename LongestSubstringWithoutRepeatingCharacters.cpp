//============================================================================
// Given a string, find the length of the longest substring without repeating
// characters. For example,
//
// the longest substring without repeating letters for "abcabcbb" is "abc",
// which the length is 3. For "bbbbb" the longest substring is "b", with the
// length of 1.
//============================================================================

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int app[256];
        memset(app, -1, sizeof(app));
        int start = 0, end = 0, maxL = 0;
        int size = s.length();
        while(end<size){
            int idx = s[end];
            if(app[idx]>=0){
                maxL = max(maxL, end-start);
                start = app[idx] + 1;
                end = start;
                memset(app, -1, sizeof(app));
                continue;
            }else{
                app[idx]=end;
                end++;
            }
        }
        maxL = max(maxL, size-start);
        return maxL;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = 0;
        int end = 0;
        bool visited[256] = {false};
 
        while (end < s.size()) {
            if (visited[(int)s[end]]) {
                res = max(res, end - start);
                while (s[start] != s[end])
                    visited[(int)s[start++]] = false;
                start++;
                end++;
            } else {
                visited[(int)s[end]] = true;
                end++;
            }
        }
        res = max(res, end - start);
        return res;
    }
};
