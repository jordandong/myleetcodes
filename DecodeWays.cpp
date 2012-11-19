class Solution {
public:
    int numDecodings(string s) {
        int l = s.size();
        if (l==0)
            return 0;
        vector<int> r(l+1,0);
        
        if (s[l-1]=='0')
            r[l-1] = 0;
        else 
            r[l-1] = 1;
        
        r[l]=1;
        for (int i = l-2; i>=0; i--) { //然后从倒数第二个字符往前推
            if (s[i]=='0')
                r[i] = 0;
            else{
                r[i] = r[i+1];
                if((s[i]-'0')*10+s[i+1]-'0' <= 26)
                    r[i] = r[i] + r[i+2];        
            }
        }
        return r[0];
    }
};
