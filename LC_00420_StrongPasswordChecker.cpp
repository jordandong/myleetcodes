/*
A password is considered strong if below conditions are all met:
1. It has at least 6 characters and at most 20 characters.
2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password.
If s is already strong, return 0.
Insertion, deletion or replace of any one character are all considered as one change.
*/

class Solution {
public:
    int strongPasswordChecker(string s) {
        bool lower = false, upper = false, digit = false;
        int required = 0, removed = 0, replaced = 0, inserted = 0;
        int repeat = 0, len = s.length();
        char prev = '\0', total = 0;
        int MINI_LEN = 6, MAXI_LEN = 20, REP_LEN = 3;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            lower |= (c >= 'a' && c <= 'z'); //lower case
            upper |= (c >= 'A' && c <= 'Z'); //upper case
            digit |= (c >= '0' && c <= '9'); //digit case
            if (c == prev) {
                if(++repeat == REP_LEN) {
                    if (len > MAXI_LEN) { //remove 3rd char
                        if (i + 1 < s.length() && c == s[i + 1]) {
                            //if more than three repeating, relpaced first, e.g "aaaabbaaabbaaa123456A"
                            replaced++;
                            repeat = 0;
                            prev = '\0';
                        } else {
                            len--;
                            removed++;
                            repeat--;
                        }
                    } else if (len >= MINI_LEN && len <= MAXI_LEN) { //replace 3rd char with required char
                        replaced++;
                        repeat = 0;
                        prev = '\0';
                    } else if (len < MINI_LEN) { //insert required char before 3rd char
                        inserted++;
                        repeat = 1;
                        len++;
                        prev = '\0';
                    }
                }
            } else {
                prev = c;
                repeat = 1;
            }
        }
        required = !lower + !upper + !digit;
        total = required - replaced - inserted;
        if (total < 0) { // all used when relpacing and inserting
            total = replaced + inserted + removed;
        } else {
            total += (replaced + inserted + removed); //adding required case as well
        }
        
        if (len > MAXI_LEN) {
            total += (len - MAXI_LEN);
        }
        if (len + required < MINI_LEN) {
            total += (MINI_LEN - len - required);
        }
        return total;
    }
};
