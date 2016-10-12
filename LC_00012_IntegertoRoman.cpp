/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

Hide Tags Math String
*/

class Solution {
public:
    string intToRoman(int num) {
        string dict[4];
        int base = 1000;
        string res = "";
        
        while(num){
            switch(base){
                case 1:
                    dict[0] = "I";
                    dict[1] = "IV";
                    dict[2] = "V";
                    dict[3] = "IX";
                    break;
                case 10:
                    dict[0] = "X";
                    dict[1] = "XL";
                    dict[2] = "L";
                    dict[3] = "XC";
                    break;
                case 100:
                    dict[0] = "C";
                    dict[1] = "CD";
                    dict[2] = "D";
                    dict[3] = "CM";
                    break;
                case 1000:
                    dict[0] = "M";
                    break;
                default:
                    break;
            }    
            
            int d = num/base;
            while(d){
                if(d == 9){
                    res += dict[3];
                    d -= 9;
                }else if(d >= 5 ){
                    res += dict[2];
                    d -= 5;
                }else if(d == 4){
                    res += dict[1];
                    d -= 4;
                }else{
                    res += dict[0];
                    d -= 1;
                }
            }
            num = num % base;
            base /= 10;
        }
        return res;
    }
};

class Solution {
public:
    map<int, string> dict;
    string intToRoman(int num) {
        dict.clear();
        dict[1] = "I";
        dict[4] = "IV";
        dict[5] = "V";
        dict[9] = "IX";
        dict[10] = "X";
        dict[40] = "XL";
        dict[50] = "L";
        dict[90] = "XC";
        dict[100] = "C";
        dict[400] = "CD";
        dict[500] = "D";
        dict[900] = "CM";
        dict[1000] = "M";
        string result = "";
        for (map<int, string>::reverse_iterator it = dict.rbegin(); it != dict.rend(); it++) {
            while (num >= it->first) {
                result += it->second;
                num -= it->first;
            }
        }
        return result;
    }
};
