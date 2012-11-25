//============================================================================
// Wildcard Matching
// Implement wildcard pattern matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
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
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false
//============================================================================

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *str, *pat;
        bool star = false;
        
        for (str = s, pat = p; *str != '\0'; ++str, ++pat)
        {
            switch(*pat)
            {
                //  meet '?', match
                case '?':
                    break;
                case '*':
                    star = true;
                    s = str, p = pat;
                    //reduce many '*' to one '*'
                    do
                    {
                        ++p;
                    }while(*p == '*');
                     // after '*', it is '/0', return true
                    if (!*p)
                        return true;
                        
                    //set p to the pos after '*' and s to the pos after last match
                    //suppose don't use '*' to match now
                    str = s - 1;
                    pat = p - 1;
                    break;
                default:
                    if (*str != *pat)
                    {
                        // if no '*' before，fail to match
                        if (!star)
                            return false;
                        // if there was a * before, we need to use it to match one morechar in s
                        ++s;
                        str = s - 1;
                        pat = p - 1;
                    }
                    break;
            }
        }
        
        //when s is used up, if p left, check if all of them are '*'
        while (*pat == '*')
            ++pat;
        return (!*pat);
    }
};


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s || !p )
            return false;
            
        const char *nextStar = strchr(p, '*');

        if ( !nextStar)
            return strCmp(s, p);

        if (!strCmpN(s, p, nextStar - p) )
            return false;

        do {
            s += nextStar - p;
            p = nextStar + 1;
            nextStar = strchr(p, '*');

            if (!nextStar)
                return strCmp(max(s, s + strlen(s) - strlen(p)), p);

            s = strStrN(s, p, nextStar - p);
        } while (s);

        return false;
    }

private:
    // Find substring of str that match length-n pattern p;
    // Consider '?' but not '*'
    const char *strStrN(const char *str, const char *p, int n) {
        const char *strEnd = str + strlen(str) - n + 1;
        while (str < strEnd && !strCmpN(str, p, n))
            str++;

        return str < strEnd ? str : NULL;
    }

    // compare if first n chars of str match length-n pattern target;
    // Consider '?' but not '*'
    bool strCmpN(const char *s, const char *p, int n) {
        const char *pEnd = p + n;
        while ( p != pEnd && *s && ( *s == *p  || *p == '?' ) ) {
            s++;
            p++;
        }
        return p == pEnd;
    }

    bool strCmp(const char *s, const char *p) {
        int n = strlen(p);
        if (strlen(s) != n)
            return false;

        return(strCmpN(s, p, n));
    }
};


#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char* s, const char* p) {
        return isMatch1(s, p);
    }
	//cannot pass large testing
    bool isMatch1(const char* s, const char* p) {
        if (*s == '\0') {
            if (*p == '\0')
            	return true;
            if (*p == '*')
            	return isMatch(s,p+1);
            return false;
        }        
        if (*p == '\0')
        	return false;	
        if (*p == '?' || *p == *s)
        	return isMatch(s+1, p+1);
        if (*p=='*')
        	return isMatch(s+1,p) || isMatch(s, p+1);
        return false;
    }

    bool isMatch2(const char* s, const char* p) {
        const char *ps, *pp;
        bool star = false;
        loopStart:
        for (ps = s, pp = p; *ps; ++ps, ++pp) {
            switch (*pp) {
            case '?':
                break;
            case '*':
                star = true;
                s = ps, p = pp+1;
                if (!*p)
                	return true;
                goto loopStart;
            default:
                if (*ps != *pp)
                    goto starCheck;
                break;
            }
        }
        while (*pp == '*')
        	++pp;
        return (!*pp);
        
        starCheck:
        if (!star)
        	return false;
        s++;
        
        goto loopStart;
        return false;
    }
};

int main() {
    return 0;
}
