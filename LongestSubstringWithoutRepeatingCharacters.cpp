//============================================================================
// Given a string, find the length of the longest substring without repeating
// characters. For example,
//
// the longest substring without repeating letters for "abcabcbb" is "abc",
// which the length is 3. For "bbbbb" the longest substring is "b", with the
// length of 1.
//============================================================================

//T:O(n), S:O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool mp[256] = {false};
        int start = 0;
        int end = 0;
        int mx = 0;
        while(end < s.length()){
            if(mp[s[end]]){
                mx = max(mx, end - start);
                while(s[start] != s[end]) // stop at the first dup char and clear all the char before
                    mp[s[start++]] = false;
                start++; //new start
                end++; //new end
            }else{
                mp[s[end]] = true;
                end++;
            }
        }
        mx = max(mx, end - start);
        return mx;
    }
};

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
