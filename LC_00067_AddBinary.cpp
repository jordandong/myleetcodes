/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Hide Tags Math String
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
        int lr = max(la, lb) + 1;
        string res(lr, '0');
        if(la == 0)
            return b;
        if(lb == 0)
            return a;
        
        int ia = la -1, ib = lb - 1, ir = lr - 1;
        int carry = 0;
        while(ia >= 0 || ib >= 0){
            int s = 0;
            if(ia >= 0 && ib >= 0)
                s = (a[ia--] - '0') + (b[ib--] - '0') + carry;
            else if(ia >= 0)
                s = (a[ia--] - '0') + carry;
            else
                s = (b[ib--] - '0') + carry;
            
            res[ir--] = '0' + s % 2;
            carry = s / 2;
        }
        if(carry){
            res[ir] = '0' + carry;
            return res;
        }else{
            return res.substr(1);
        }
    }
};
