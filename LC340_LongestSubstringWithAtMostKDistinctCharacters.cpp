/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l = 0, r = 0;
        int mp[256];
        int mx = 0;
        int cnt = 0;
        memset(mp, 0, sizeof(int)*256);

        for(r = 0; r < s.length(); r++) {
            if(mp[s[r]] == 0)
                cnt++;
            mp[s[r]]++;
            while(cnt > k){
                if(--mp[s[l++]] == 0)
                    cnt--;
            }
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};
