//============================================================================
// The gray code is a binary numeral system where two successive values differ
// in only one bit.
//
// Given a non-negative integer n representing the total number of bits in the
// code, print the sequence of gray code. A gray code sequence must begin with
// 0.
//
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
//============================================================================

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int num = 1 << n;
        for (int i = 0; i < num; i++) {
            result.push_back((i >> 1) ^ i);
        }
        return result;
    }
};

int main() {
    return 0;
}


class Solution{
public:
    vector<int> grayCode(int n){
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        stack<int> s;
    
        if (n<=0)
            return vector<int>(1, 0);
            
        res.push_back(0);
        res.push_back(1);
        
        for(int i=1; i<n; ++i){
            int highest = 1<<i;
        
            for (vector<int>::const_iterator it=res.begin();it!=res.end();++it){
                s.push(*it|highest);
            }//generate the second half by setting the highest bit using the first half of gray codes
 
            while(!s.empty()){
                res.push_back(s.top());
                s.pop();
            }//mirror reflect
        }    
        return res;
    }
};




class Solution{
public:
    vector<int> grayCode(int n){
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
    
        if (n<=0)
            return vector<int>(1, 0);
        
        int size = 1<<n;
        res.push_back(0);
        res.push_back(1);
        
        for(int i=0; i<=size-3; ++i){
            int next = *res.rbegin(); get the last element
            //flip the rightmost bit
            if(i%2==1){
                next = next^1;
            	res.push_back(next);
            }
            //flip the left bit of the first setting bit from right
            else{
            	int check = 0;
            	while(!((1<<check)&next))
            		check++;  
              check++;
                
            	next = next^(1<<check);
            	res.push_back(next);
            }
        }    
        return res;
    }
};
