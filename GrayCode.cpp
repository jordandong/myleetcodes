/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

Hide Tags Backtracking
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int num = 1 << n;
        //x          1110001100  1 0 00000
        //x/2        0111000110  0 1 00000
        //(x - 1)    1110001100  0 1 11111
        //(x - 1)/2  0111000110  0 0 11111
        for(int i = 0; i < num; i++)
            res.push_back((i >> 1) ^ i);
        return res;
    }
};

class Solution{
public:
    vector<int> grayCode(int n){
        vector<int> res;
        stack<int> s;
    
        if(n <= 0)
            return vector<int>(1, 0);
            
        res.push_back(0);
        res.push_back(1);
        
        for(int i = 1; i < n; ++i){
            int highest = 1 << i;
        
            for(auto it = res.begin(); it != res.end(); ++it)
                s.push(*it | highest);//generate the second half by setting the highest bit using the first half of gray codes
 
            while(s.size()){
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
        vector<int> res;
        if(n <= 0)
            return vector<int>(1, 0);
        
        int sz = 1 << n;
        res.push_back(0);
        res.push_back(1);
        
        for(int i = 0; i < sz - 2; ++i){
            int next = *res.rbegin(); //get the last element
            //flip the rightmost bit
            if((i & 1) == 1){
                next = next^1;
            	res.push_back(next);
            }else{//flip the left bit of the first setting bit from right
            	int check = 0;
            	while(0 == ((1<<check) & next))
            		check++;
            	check++;
                
            	next ^= (1<<check);
            	res.push_back(next);
            }
        }    
        return res;
    }
};
