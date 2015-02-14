/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

Hide Tags Math String
*/

class Solution {
public:
    bool isNumber(string s) {
        int start = 0;
        int end = s.length() - 1;
        // trim leading/trailing spaces
        while(start <= end && s[start] == ' ')
            start++;
        if(start > end)
            return false;
        while(s[end] == ' ')
            end--;

        // skip leading +/-
        if (s[start]== '+' || s[start] == '-')
            start++;

        bool num = false; // is a digit
        bool dot = false; // is a '.'
        bool exp = false; // is a 'e'
        while(start <= end) {
            if (s[start] >= '0' && s[start] <= '9') {
                num = true;
            }else if (s[start] == '.') {
                if(exp || dot)
                    return false;
                dot = true;
            }else if (s[start] == 'e') {
                if(exp || num == false)
                    return false;
                exp = true; 
                num = false;
            }else if (s[start] == '+' || s[start] == '-') {
                if (s[start - 1] != 'e')
                    return false;
            }else {
                return false;
            }
            start++;
        }
        return num;
    }
};

bool isNumber(const char* s) {
    // trim leading/trailing spaces
    while(*s != '\0' && *s == ' ')
        s++;
    if(*s == '\0')
        return false;
    const char *e = s + strlen(s) - 1;
    while(*e == ' ')
        e--;

    // skip leading +/-
    if (*s == '+' || *s == '-')
        s++;

    bool num = false; // is a digit
    bool dot = false; // is a '.'
    bool exp = false; // is a 'e'
    while(s <= e) {
        if (*s >= '0' && *s <= '9') {
            num = true;
        }else if (*s == '.') {
            if(exp || dot)
                return false;
            dot = true;
        }else if (*s == 'e') {
            if(exp || num == false)
                return false;
            exp = true;
            num = false;
        }else if (*s == '+' || *s == '-') {
            if (*(s-1) != 'e')
                return false;
        }else {
            return false;
        }
        s++;
    }
    return num;
}
