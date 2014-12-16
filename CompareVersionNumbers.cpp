/*
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
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
    
        while(dot1<l1 && dot2<l2){
            last_dot1 = dot1;
            last_dot2 = dot2;
            dot1++;
            dot2++;
            while(dot1<l1 && version1[dot1]!='.'){
                dot1++;
            }
            while(dot2<l2 && version2[dot2]!='.'){
                dot2++;
            }

            i = dot1-1;
            j = dot2-1;
            while(i > last_dot1 && j > last_dot2){
                if(version1[i] > version2[j]){
                    ver = 1;
                }else if(version1[i] < version2[j]){
                    ver = -1;
                }
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
        
        i = dot1+1;
        j = dot2+1;
        while(i < l1){
            if(version1[i] == '0' || version1[i] == '.'){
                i++;
            }else{
                ver = 1;
                return ver;
            }
        }
        
        while(j <l2){
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
