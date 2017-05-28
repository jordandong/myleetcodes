/*
Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.

Example 1:
Input: 5
Output: 5
Explanation: 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Note: 1 <= n <= 109

Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming
Hide Similar Problems (E) House Robber (M) House Robber II (M) Ones and Zeroes
Have you met this question in a real interview? Yes  
*/

class Solution {
public:
    int findIntegers(int num) {
        int N = getLen(num);
        vector<int> dp_0(N, 0), dp_1(N, 0); //the total amout at starting pos i with 0 or 1
        dp_0[0] = 1; //0
        dp_1[0] = 1; //1
        for (int i = 1; i < N; i++) {
            dp_0[i] = dp_0[i - 1] + dp_1[i - 1]; //01 , 00 ...
            dp_1[i] = dp_0[i - 1]; //10 , ...
        }
        int res = dp_0[N - 1] + dp_1[N - 1]; //starting pos N - 1, including case 1YXXXXX and case 0XXXXXX, Y must be 0
        for (int i = N - 2; i >= 0; i--) {
            if (getPos(num, i) == 1 && getPos(num, i + 1) == 1) { //both are ones, must be contains max amount
                return res;
            } else if (getPos(num, i) == 0 && getPos(num, i + 1) == 0) { //minus one at pos i case, it is bigger 
                res -= dp_1[i];
            }
        }
        return res;
    }
private:
    int getLen(int num) {
        int n = 0;
        while (num) {
            n++;
            num >>= 1;
        }
        return n;
    }
    
    int getPos(int num, int pos) {
        return (num & (1 << pos)) ? 1 : 0;
    }
};

class Solution {
public:
    int findIntegers(int num) {
        int N = getLen(num);
        vector<int> dp_0(N, 0), dp_1(N, 0); //the total amout at starting pos i with 0 or 1, 1 based
        dp_0[0] = 1;
        dp_1[0] = 0;
        for (int i = 1; i < N; i++) {
            dp_0[i] = dp_0[i - 1] + dp_1[i - 1]; //0 , 00 01...
            dp_1[i] = dp_0[i - 1]; //1 , 10 ...
        }
        int res = dp_0[N - 1] + dp_1[N - 1]; //including 10XXXXXX case and case 01XXXXXXX 
        for (int i = N - 1; i >= 1; i--) {
            if (getPos(num, i) == 1) {
                res += (dp_0[i - 1] + dp_1[i - 1]); //plus YYYYY10XXXXX case and YYYYY01XXXXX case 
                if (getPos(num, i + 1) == 1) //both are ones, must be contains max amount
                    return res;
            }
        }
        return res + 1; //plus itself
    }
private:
    int getLen(int num) {
        int n = 0;
        while (num) {
            n++;
            num >>= 1;
        }
        return n;
    }
    
    int getPos(int num, int pos) {
        return (num & (1 << (pos - 1))) ? 1 : 0;
    }
};
