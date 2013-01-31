//============================================================================
// Given two binary strings, return their sum (also a binary string).
//
// For example,
// a = "11"
// b = "1"
// Return "100".
//
//============================================================================

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string::iterator i = a.begin();
        string::iterator j = b.begin();
        string c;
        int carry = 0;
        while (true) {
            int ac, bc;
            if (i != a.end())
	            	ac = *(i++) - '0';
            else
	            	ac = 0;
            if (j != b.end())
	            	bc = *(j++) - '0';
            else
	            	bc = 0;
            int s = ac + bc + carry;
            c.push_back('0' + (s % 2));
            carry = s / 2;
            if (i == a.end() && j == b.end())
	            	break;
        }
        if (carry == 1)
        		c.push_back('1');
        reverse(c.begin(), c.end());
        return c;
    }
};

int main() {
    return 0;
}


class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return addBC(a,b,0);
    }
    
    string addBC(string a, string b, int carry){
        int lena = a.length();
        int lenb = b.length();
        if(lena==0&&lenb==0){
            if(carry)
                return "1";
            else
                return "";
        }
        
        int na;
        int pa = lena==0?0:lena-1;
        if(lena==0)
            na = 0;
        else
            na = a[lena-1]-'0';
            
            
        int nb;
        int pb = lenb==0?0:lenb-1;
        if(lenb==0)
            nb = 0;
        else
            nb = b[lenb-1]-'0';
            
        string res;
        res.push_back('0'+(na+nb+carry)%2);
        carry = (na+nb+carry)/2;
        
        return addBC(a.substr(0,pa), b.substr(0,pb), carry) + res;
        
    }
};


class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return addBC(a,b,0);
    }
    
    string addBC(string a, string b, int carry){
        int lena = a.length()-1;
        int lenb = b.length()-1;
        string res;
        
        if(lena<0&&lenb<0){
            if(carry)
                return "1";
            else
                return res;
        }
        
        if(lena<0&&lenb>=0){
            if(carry){
                if(b.at(lenb)=='1'){
                    res ="0";
                    return addBC("", b.substr(0,lenb), 1)+res;
                }
                else{
                    res = "1";
                    return b.substr(0,lenb) + res;
                }
            }else{
                return b.substr(0,lenb+1); 
            }
        }
        
        if(lenb<0&&lena>=0){
            if(carry){
                if(a.at(lena)=='1'){
                    res ="0";
                    return addBC(a.substr(0,lena),"", 1) +res;
                }
                else{
                    res = "1";
                    return a.substr(0,lena) + res;
                }
            }else{
                return a.substr(0,lena+1);
                
            }
        }
        
        
        if(lena>=0&&lenb>=0){
            if(a.at(lena)=='1'&&b.at(lenb)=='1'){
                if(carry){
                    res ="1";
                    return addBC(a.substr(0,lena),b.substr(0,lenb),1)+res;
                }
                else{
                    res ="0";
                    return addBC(a.substr(0,lena),b.substr(0,lenb),1)+res;
                    
                }
            }
            
            if(a.at(lena)=='1'&&b.at(lenb)=='0'){
                if(carry){
                    res ="0";
                    return addBC(a.substr(0,lena),b.substr(0,lenb),1)+res;
                }
                else{
                    res ="1";
                    return addBC(a.substr(0,lena),b.substr(0,lenb),0)+res;
                    
                }
            }
            
            if(a.at(lena)=='0'&&b.at(lenb)=='1'){
                if(carry){
                    res ="0";
                    return addBC(a.substr(0,lena),b.substr(0,lenb),1)+res;
                }
                else{
                    res ="1";
                    return addBC(a.substr(0,lena),b.substr(0,lenb),0)+res;
                    
                }
            }
            if(a.at(lena)=='0'&&b.at(lenb)=='0'){
                if(carry){
                    res ="1";
                    return addBC(a.substr(0,lena),b.substr(0,lenb),0)+res;
                }
                else{
                    res ="0";
                    return addBC(a.substr(0,lena),b.substr(0,lenb),0)+res;
                    
                }
            }
        }
    }
};
