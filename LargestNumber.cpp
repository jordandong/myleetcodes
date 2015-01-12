/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

bool str_cmp (string a, string b) {
    return (a+b < b+a);
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> num_copy;
        string res;
        int zero = 0;
        for(int e : num){
            if(e == 0)
                zero++;    	
            num_copy.push_back(num2str(e));
        }
        if(zero == num.size())
            return "0";

        sort(num_copy.begin(), num_copy.end(), str_cmp);
        for(int i = num_copy.size() - 1; i >= 0 ; i--){
            res+=num_copy[i];
        }
        return res;
    }

    string num2str(int a){
        string s;
        do{
            s.push_back((a%10) + '0');
            a/=10;
        }while(a);
        reverse(s.begin(), s.end());
        return s;
    }
};
