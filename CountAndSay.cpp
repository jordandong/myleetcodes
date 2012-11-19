class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1)
            return ""; 
        string s="1";
        for (int i=1;i<n;i++){
            s=cAS(s);
        }
        return s;
    }

    string cAS(string &s){
        string res;
        char cur_str=s.at(0);
        int num=0;
        for (int i=0;i<s.length();i++)
        {
			if (cur_str==s.at(i))
				num++;
			else{
				stringstream ss;
				ss<<num<<cur_str;
				res+=ss.str();
				cur_str=s.at(i);
				num=1;
			} 		
        }
	    if (num>0){
            stringstream ss;                   
            ss << num << cur_str;
            res += ss.str();
        }
        return res;
    }
};
