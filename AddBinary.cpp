#include<iostream>
#include<string>
using namespace std;

int main(){

	string a="12345";
	cout<<a.substr(0,0).length()<<endl;;
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
