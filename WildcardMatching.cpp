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
//=========================================================================

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (!p)
			return !s;
		if (!s)
			return !p;
		for (const char *star=NULL, *s_save=s; *s; ) { 
		//star是上一个*出现的位置；s_save+1是出现不匹配时，s应该回到的位置。
			if (*p == '*') {
				star = p++;
				s_save = s;
			} else if ( *p != '?' && *s != *p) {  // 不匹配
				if (!star) { // 没有*来做灵活匹配
					return false;
				} else {  // 有*， 回到star+1 和 s_save+1匹配
					p = star+1;
					s = ++s_save;
				}
			} else {  // 匹配时，p和s都前进到下一个
				s++;
				p++;
			}
		}
		while (*p == '*')
			p++; // pattern结尾的*可以消耗掉
		return !*p;  // 看是否已经到p的末尾
	}
		
	bool isMatch2(const char *str, const char *pat, bool hasStar=false) {
		if (!*pat)
			return !*str || hasStar;
		const char *s, *p;
		for (s = str, p = pat; *s; ++s, ++p) {//str is the pos after the match char, pat is pos where after *
			if (*p == '*') 
				return isMatch(s, p+1, true);  
			else if ( *p != '?' && *s != *p) 
				return !hasStar ? false : isMatch(str+1, pat, hasStar);//str+1, use a char in str
		}

		while (*p == '*')
			++p;
		return (!*p);
	}

	bool isMatch3(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n=strlen(s);
		int m=strlen(p);

		int i=0;
		int j=0;
		int star=-1;
		int sp=0;

		while(i<n){//s is not null
			//one * and multiple *, same effect
			while(j<m && p[j]=='*'){
				star=j++;  //* match 0 character, pos of star
				sp=i;    //pos of first unmatched char in s 
			}
			//p is null or not match
			if(j==m || (p[j]!=s[i] && p[j]!='?')){
				if(star<0)	//if no match with no star, fail
					return false;
				else{
					j=star+1;//unmatched, go back to the first char after *
					i=++sp;     //* match 1 more character, s gets next char
				}
			}
			//match char in s and p
			else{
				i++;
				j++;
			}
		}

		while(j<m && p[j]=='*')
			j++;
		return j==m;
	}
};


class Solution {
	public:
		bool isMatch(const char *s, const char *p) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			const char *str, *pat;
			bool star = false;

			for (str = s, pat = p; *str != '\0'; ++str, ++pat){
				switch(*pat){
					//  meet '?', match
					case '?':
						break;
					case '*':
						star = true;
						s = str, p = pat;
						//reduce many '*' to one '*'
						do{
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
						if (*str != *pat){
							// if no '*' before，fail to match
							if (!star)
								return false;
							// if there was a * before, we need to use it to match one more char in s
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

//DP, cannot pass large testing
class Solution {
	public:
		bool isMatch(const char *s, const char *p){
			int n=strlen(s);
			int m=strlen(p);
			bool dp[2][n+1];
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < n+1; j++) 
					dp[i][j] = false;
			}
			dp[m%2][n]=true;
			for(int i=m-1;i>=0;i--)
			{
				for (int j=0;j<n+1;j++) {
					dp[i%2][j] = false;
				}
				dp[i%2][n]=(p[i]=='*' && dp[(i+1)%2][n]); //use the char in P match the empty char after the last char in s 

				for(int j=n-1;j>=0;j--)    
					if(p[i]=='*')
						dp[i%2][j]=(dp[(i+1)%2][j] || dp[i%2][j+1]);  //use * to match nothing or use * to match one char in s
					else
						dp[i%2][j]=((p[i]==s[j] || p[i]=='?') && dp[(i+1)%2][j+1]);	//use char in p to match char in s

			}
			return dp[0][0];    
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
		//Can pass large testing
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

