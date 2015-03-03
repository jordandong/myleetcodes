/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags String
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = version1.length();
        int l2 = version2.length();
        int ver = 0;
        int dot1 = -1;
        int dot2 = -1;
        int last_dot1;
        int last_dot2;
        int i, j;
    
        while(dot1 < l1 && dot2 < l2){
            last_dot1 = dot1;
            last_dot2 = dot2;
            dot1++;
            dot2++;
            while(dot1 < l1 && version1[dot1] != '.')
                dot1++;
            while(dot2 < l2 && version2[dot2] != '.')
                dot2++;

            i = dot1 - 1;
            j = dot2 - 1;
            while(i > last_dot1 && j > last_dot2){
                if(version1[i] > version2[j])
                    ver = 1;
                else if(version1[i] < version2[j])
                    ver = -1;
                i--;
                j--;
            }

            while(i > last_dot1){
                if(version1[i] == '0'){
                    i--;
                }else{
                    ver = 1;
                    return ver;
                }
            }
        
            while(j > last_dot2){
                if(version2[j] == '0'){
                    j--;
                }else{
                    ver = -1;
                    return ver;
                }
            }
            if(ver != 0)
                return ver;
        }
        
        //tailing zeors, dots, ...
        i = dot1 + 1;
        j = dot2 + 1;
        while(i < l1){
            if(version1[i] == '0' || version1[i] == '.'){
                i++;
            }else{
                ver = 1;
                return ver;
            }
        }
        
        while(j < l2){
            if(version2[j] == '0' || version2[j] == '.'){
                j++;
            }else{
                ver = -1;
                return ver;
            }
        }
        return 0;
    }
};

class Solution {
public:
   int compareVersionHelper(string &s, int &begin){
       while(begin < s.length() && s[begin] == '0')//heading zeros
           begin++;
       int end = begin;
       while(end < s.length() && s[end] != '.')
           end++;
       return end - begin;
   }
   
    int compareVersion(string version1, string version2) {
        int begin1 = 0;
        int begin2 = 0;
        while(begin1 < version1.length() || begin2 < version2.length()) {
            int l1 = compareVersionHelper(version1, begin1);
            int l2 = compareVersionHelper(version2, begin2);
            if (l1 < l2) 
                return -1;
            if (l1 > l2)
                return 1;
            for(int i = 0; i < l1; ++i) {
                if(version1[begin1] < version2[begin2])
                    return -1;
                if(version1[begin1] > version2[begin2])
                    return 1;
                begin1++;
                begin2++;
            }
            begin1++;
            begin2++;
        }
        return 0;
    }
};
