//============================================================================
// Regular Expression Matching
// Implement regular expression matching with support for '.' and '*'.
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true
//============================================================================

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int p_len = strlen(p);
        int s_len = strlen(s);
        if(p_len == 0)
            return p_len == s_len;
	
        bool dp[s_len + 1][p_len + 1] = {false};
        memset(dp, 0, sizeof(bool)*(s_len+1)*(p_len+1));
        dp[0][0] = true;

        for(int j = 0;j < p_len; j++){
            if(p[j] =='*') {
                if(dp[0][j-1])  //match null in s
                    dp[0][j+1] = true;
                    
                if(p[j-1] != '.'){
                    for(int i = 0; i < s_len; i++){
                        if(dp[i+1][j] || dp[i+1][j-1] || (i>0 && dp[i][j+1] && s[i]==s[i-1] && s[i-1]==p[j-1]))
                        //p = ..xy*, match cur s to y || match cur s to x || match last s to * and cur s must equal to last s 
                            dp[i+1][j+1] = true;
                    }
                } else {
                    int i=0;
                    while(i < s_len && !dp[i+1][j-1] && !dp[i+1][j])//found the first match place
                        i++;
                    for(; i < s_len; i++)//set all the other places
                        dp[i+1][j+1] = true;
                }
            }else{
                for(int i = 0;i < s_len; i++){//regular cases
                    if(s[i] == p[j] || p[j] == '.')
                        dp[i+1][j+1] = dp[i][j];
                }
            }
        }
        return dp[s_len][p_len];
    }
};

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0')
            return *s == '\0';
        
        if (*(p+1) != '*') { //regular cases
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        
        // next char is '*'
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p+2)) //* match 0 char at the first time
                return true;
            //increase s, match one more *
            s++;
        }
        //have matched all *
        return isMatch(s, p+2);
    };
};
