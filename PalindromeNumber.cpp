/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

Hide Tags Math
*/

class Solution {
public:
    bool isPalindrome(int x) {
        int p = 0;
        int q = x;
        while(x ! =0){
            p *= 10;
            p += (x % 10);
            x/=10;
        }
        return p==q && q>=0; //if overfow,  then non-equal
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int d = 1;
        while(x/d >= 10) //find the highest digit
            d*=10;
        while (x != 0){
            if (x/d != x%10)
                return false;
            x= (x%d)/10;//remove both the highest and lowest digits
            d/=100;
        }
        return true;
    }
};
