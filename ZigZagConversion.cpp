/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
Hide Tags String
*/
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(nRows <= 1)
            return s;
        string ret;
        int offset = 2 * nRows - 2;
        for(int i = 0; i<nRows; i++) {
            for(int base = i; ;base += offset) {
                if(base >= s.size())
                    break;
                ret.push_back(s[base]);
                if(i > 0 && i < nRows - 1) {
                    //middle need add ziggggging char
                    int t = base + offset - 2 * i;
                    if(t < s.size())
                        ret.push_back(s[t]);
                }
            }
        }
        return ret;
    }
};

class Solution{
public:
    string convert(string s, int nRows){
        if (nRows < 2)
        	return s;
        int N = s.size();
        int L = 2 * (nRows - 1); // provide offset
        string res;
        
        for (int i = 0; i < N; i += L)//first row
            res.push_back(s[i]);
    
        for (int i = 1; i < nRows - 1; i++){
            for (int j = i; j < N; j += L){
                res.push_back(s[j]);
                // j - i: provide offset L for each row
                // L - i: provide reverse for each column
                int k = (j - i) + (L - i);
                if (k < N)
                	res.push_back(s[k]);
            }
        }

        for (int i = nRows - 1; i < N; i += L) //last row
            res.push_back(s[i]);
        return res;
    }
};
