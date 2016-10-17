/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Hide Tags Math String
*/

class Solution {
public:
    int romanToInt(string s) {
        int mp[26];
        mp['I' - 'A'] = 1;
        mp['V' - 'A'] = 5;
        mp['X' - 'A'] = 10;
        mp['L' - 'A'] = 50;
        mp['C' - 'A'] = 100;
        mp['D' - 'A'] = 500;
        mp['M' - 'A'] = 1000;
        int res = 0;
        int i = 0;
        for(i = 0; i < s.length()-1; i++){
            if(mp[s[i] - 'A'] < mp[s[i+1] - 'A'])
                res -= mp[s[i] - 'A'];
            else
                res += mp[s[i] - 'A'];
        }
        res += mp[s[i] - 'A'];
        return res;
    }
};

class Solution {
public:
    map<char, int> dict;
    int romanToInt(string s) {
        dict['M'] = 1000;
        dict['D'] = 500;
        dict['C'] = 100;
        dict['L'] = 50;
        dict['X'] = 10;
        dict['V'] = 5;
        dict['I'] = 1;
        int res = 0;
        int i = 0;
        while (i < s.size() - 1) {
            if (dict[s[i]] < dict[s[i+1]])
            	res -= dict[s[i]];
            else
            	res += dict[s[i]];
            i++;
        }
        res += dict[s[i]];
        return res;
    }
};
