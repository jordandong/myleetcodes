/*
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".

Hide Tags Two Pointers String
Hide Similar Problems (E) Reverse String
*/

class Solution {
public:
    string reverseVowels(string s) {
        int j = s.length() - 1;
        int i = 0;
        bool dict[256] = {0};
        dict['A'] = true;
        dict['E'] = true;
        dict['I'] = true;
        dict['O'] = true;
        dict['U'] = true;
        dict['a'] = true;
        dict['e'] = true;
        dict['i'] = true;
        dict['o'] = true;
        dict['u'] = true;
        
        while (i < j) {
            if (dict[s[i]] && dict[s[j]])
                swap(s[i++], s[j--]);
            else if(dict[s[i]])
                j--;
            else
                i++;
        }
        return s;
    }
};

class Solution {
public:
    string reverseVowels(string s) {
        int j = s.length() - 1;
        int i = 0;
        while (i < j) {
            if (isVowels(s[i]) && isVowels(s[j]))
                swap(s[i++], s[j--]);
            else if(isVowels(s[i]))
                j--;
            else
                i++;
        }
        return s;
    }
    
    bool isVowels(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
    }
};
