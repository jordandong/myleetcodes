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
        if (*p == '\0')
            return *s == '\0';
	//compare this pos and recursion
        if (*(p+1) != '*') {
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        // next char is '*'
        //judge x* is 0 or more than zero
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            //x* is 0
            if (isMatch(s, p+2))
                return true;
            //x* is more than 0
            s++;
        }
        
        //finish using x*
        return isMatch(s, p+2);
    };
};








#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        assert(s && p);
        if (*p == '\0')
        	return *s == '\0';

        if (*(p+1) != '*') {
            assert(*p != '*');
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        // next char is '*'
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    };
};

int main() {
    return 0;
}
