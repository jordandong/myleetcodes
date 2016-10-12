/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.

Hide Tags Hash Table Math
*/

/*
   0.16  
6 ) 1.00
    0 
    1 0       <-- Remainder=1, mark 1 as seen at position=0.
    - 6 
      40      <-- Remainder=4, mark 4 as seen at position=1.
    - 36 
       4      <-- Remainder=4 was seen before at position=1, so the fractional part which is 16 starts repeating at position=1 => 1(6).
The key insight here is to notice that once the remainder starts repeating, so does the divided result.

You will need a hash table that maps from the remainder to its position of the fractional part. Once you found a repeating remainder, you may enclose the reoccurring fractional part with parentheses by consulting the position from the table.

The remainder could be zero while doing the division. That means there is no repeating fractional part and you should stop right away.

Just like the question Divide Two Integers, be wary of edge case such as negative fractions and nasty extreme case such as -2147483648 / -1.
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long x = numerator;
        long long y = denominator;
        long long r = 0;
        ostringstream out;
        vector<int> cir;
        unordered_map<int, int> last_r;

        if(x == 0)
            return "0";

        if(x < 0){
            x = -x;
            y = -y;
        }
        if(y < 0){
            y = -y;
            out<<"-";
        }
        
        out<<(x / y);
        r = x % y;
        if(r == 0)
            return out.str();
            
        out<< ".";
        
        for(int i = 0; r && (last_r.find(r) == last_r.end()); i++){
            last_r[r] = i;//add new remainder index at cir.
            r *= 10;
            cir.push_back(r/y);
            r = r%y;
        }
        
        if(r){
            for(int i = 0; i < last_r[r]; i++)
                out<<cir[i];
            out<<"(";
            for(int i = last_r[r]; i < cir.size(); i++)
                out<<cir[i];
            out<<")";
        }else{
            for(int i = 0; i < cir.size(); i++)
                out<<cir[i];
        }
        return out.str();
    }
};
