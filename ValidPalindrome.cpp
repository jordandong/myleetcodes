/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = s.length()-1;
        
        while(l<=r){
            if(!isalnum(s[l]))
                l++;
            else if(!isalnum(s[r]))
                r--;
            else if(abs(s[l] - s[r]) == 0 || abs(s[l] - s[r]) == ('a' - 'A')){
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};


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
