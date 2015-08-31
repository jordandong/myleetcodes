/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Hint:
1. Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
2. Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
3. There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)

Hide Tags Math String
*/

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string res = "";
        string mp[4] = {" Billion", " Million", " Thousand", ""};
        int base = 1000000000;
        int idx = 0;
        while (base) {
            int digits = num / base;
            if (digits) {
                res += numberToWordsHelper(digits);
                res += mp[idx];
                num %= base;
            }
            base /= 1000;
            idx++;
        }
        return res.substr(1);
    }
    
    string numberToWordsHelper(int num) {
        string res = "";
        int base = 100;
        string mp_ones[10] = {" Zero", " One", " Two", " Three", " Four",
                                " Five", " Six", " Seven", " Eight", " Nine"};
        string mp_ten[10] = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen",
                                " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        string mp_tens[10] = {"NA", "NA", " Twenty", " Thirty", " Forty",
                                " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        while (base) {
            int digits = num / base;
            if (digits) {
                if (base == 100) {
                    res += mp_ones[digits];
                    res += " Hundred";
                } else if (base == 10) {
                    if (digits == 1) {
                        res += mp_ten[num % 10];
                        base /= 10;
                    } else {
                        res += mp_tens[digits];
                    }
                } else {
                    res += mp_ones[digits];
                }
                num %= base;
            }
            base /= 10;
        }
        return res;
    }
};
