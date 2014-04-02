//============================================================================
// Implement strStr().
//
// Returns a pointer to the first occurrence of needle in haystack,
// or null if needle is not part of haystack.
//============================================================================

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!haystack||!needle)
            return haystack;
        int l_h = strlen(haystack);
        int l_n = strlen(needle);
        if(l_n == 0)
            return haystack;
        if(l_h == 0)
            return NULL;

        int pos = KMP(haystack, needle);
        return pos==-1?NULL:haystack+pos;
    }
    
    void cal_next(vector<int> &next, char* needle){
        int l_n = strlen(needle);
        int k = -1;
        int j = 0;
        next[0] = -1;
        while(j < l_n - 1){
            if(k==-1 || *(needle+k) == *(needle+j)){
                next[++j] = ++k;
            }else{
                k = next[k];
            }
        }
    }
    
    int KMP(char *haystack, char *needle){
        int l_h = strlen(haystack);
        int l_n = strlen(needle);
        vector<int> next(l_n, 0);
        cal_next(next, needle);
        int i_h = 0;
        int i_n = 0;
        while(i_h<l_h && i_n<l_n){
            if(i_n == -1 || *(needle+i_n) == *(haystack+i_h)){
                i_n++;
                i_h++;
            }else{
                i_n = next[i_n];
            }
        }
        return i_n==l_n?i_h-i_n:-1;
    }
};





#include <cstring>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!haystack||!needle)
			return haystack;
        int n = strlen(haystack);
        int m = strlen(needle);
        int i = 0;
        while (i < n-m+1) {
            int j = 0;
            while (j < m && haystack[i] == needle[j]){
                i++;
				j++;
            }
            if (j == m)
				return haystack+(i-j);
            i = i-j+1;
        }
        return NULL;
    }
};

int main() {
    return 0;
}
