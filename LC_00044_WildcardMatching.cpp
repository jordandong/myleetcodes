/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

Hide Tags Dynamic Programming Backtracking Greedy String
*/

//using '\0'
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	if (!p || !s)
    	    return p == s;
    
        const char *star = NULL; //pos of *
        const char *pos_s = s;
    	while(*s){
    	    if (*p == '*') {
    	    	star = p++; //record * pos and move to next char in p 
    	    	pos_s = s;//pos_s is the char in s that will start to match with the char after * in p
    	    } else if( *p != '?' && *s != *p) { //no matching
    	        if(!star){ //no * to match this char in s
    	            return false;
    	        }else{  // * could match char in s
    	            p = star + 1; //move to the char after * in p again 
    	            s = ++pos_s; //char at pos_s is matched using *, move to next char after pos_s
    	        }
    	    } else {//match
    	        s++;
    	        p++;
    	    }
    	}
    	while(*p == '*')
    	    p++; // * at the end could match nothing
    	return !*p; // check if it is the end of p
    }
};

//recursion verion 
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	if (!p || !s)
    	    return p == s;
        return isMatchHelper(s, p, false);  
    }
    
    bool isMatchHelper(const char *str, const char *pat, bool hasStar) {
        if (!*pat)
    	    return !*str || hasStar;
    	const char *s, *p;
    	for (s = str, p = pat; *s; ++s, ++p) {//str is the pos after the match char, pat is pos where after *
    	    if (*p == '*') 
    	        return isMatchHelper(s, p+1, true);  
    	    else if ( *p != '?' && *s != *p) 
    	        return !hasStar ? false : isMatchHelper(str+1, pat, hasStar);//str+1, use a char in str
    	}
    	while(*p == '*')
    	    ++p;
    	return (!*p);
    }
};

//using index
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen(s);
    	int m = strlen(p);
    	int i = 0;
    	int j = 0;
    	int star = -1;
    	int sp = 0;

        while(i < n){//s is not null
            //one * and multiple *, same effect
            while(j < m && p[j]=='*'){
            	star = j++;  //* match 0 character, pos of star
            	sp = i;    //pos of first unmatched char in s
            }
            //p is null or not match
            if(j == m || (p[j] != s[i] && p[j] != '?')){
            	if(star < 0){	//if no match with no star, fail
            	    return false;
            	}else{
            	    j = star + 1;//unmatched, go back to the first char after *
            	    i = ++sp;     //* match 1 more character, s gets next char
            	}
            }else{//match char in s and p
                i++;
                j++;
            }
        }
        
        while(j < m && p[j]=='*')
            j++;
        return j == m;
    }
};

//DP, cannot pass large set testing(TLE)
class Solution {
public:
    bool isMatch(const char *s, const char *p){
    	int n = strlen(s);
    	int m = strlen(p);
    	bool dp[2][n+1];
    	for (int i = 0; i < 2; i++) {
    	    for (int j = 0; j < n+1; j++) 
    	        dp[i][j] = false;
    	}
    	
    	dp[m%2][n] = true;
    	for(int i = m-1; i >= 0; i--){
    	    dp[i%2][n] = (p[i] == '*' && dp[(i+1)%2][n]); //use the char in P match the empty char after the last char in s 
    	    for(int j = n-1; j >= 0; j--)
    	        if(p[i] == '*')
    	            dp[i%2][j] = (dp[(i+1)%2][j] || dp[i%2][j+1]);  //use * to match nothing or use * to match one char in s
    	        else
    	            dp[i%2][j] = ((p[i] == s[j] || p[i] == '?') && dp[(i+1)%2][j+1]);	//use char in p to match char in s
    	}
    	return dp[0][0];
    }
};

//recursion, cannot pass large set testing(TLE)
class Solution {
public:
    bool isMatch(const char *s, const char *p){
        if (!p || !s)
    	    return p == s;

    	if(*s == '\0') {
    	    if (*p == '\0')
    	        return true;
    	    if (*p == '*')
    	        return isMatch(s, p+1);
    	    return false;
    	}
    	
    	if (*p == '\0')
    	    return false;

    	if (*p == '?' || *p == *s)
    	    return isMatch(s + 1, p + 1);

    	if (*p == '*')
    	    return isMatch(s + 1, p) || isMatch(s, p + 1);

    	return false;
    }
};
