class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = s.length()-1;
        
        for(int i =0; i<=r; i++)
            s[i]=toupper(s[i]);
        
        
        while(l<=r){
            if(!isalnum(s[l]))
                l++;
            else if(!isalnum(s[r]))
                r--;
            else if(toupper(s[l])==toupper(s[r])){
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};
