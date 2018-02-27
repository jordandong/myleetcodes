/*
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.
A number is valid if each digit remains a digit after rotation.
0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other;
6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

Note:
N will be in range [1, 10000].
*/

class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; i++)
            if (good(i))
                res++;
        return res;
    }

private:
    bool good(int x) {
        string s = to_string(x);
        bool diff = false;
        for (char ch : s) {
            if (ch == '3' || ch == '4' || ch == '7')
                return false;
            if (ch == '2' || ch == '5' || ch == '6' || ch == '9')
                diff = true;
        }
        return diff;
    }
};

class Solution {
public:
    int rotatedDigits(int N) {
        vector<int> allPossibleCount = {1, 2, 3, 3, 3, 4, 5, 5, 6, 7}; // 0, 1, 2, 5, 6, 8, 9
        vector<int> excludeNumCount = {1, 2, 2, 2, 2, 2, 2, 2, 3, 3}; // 0, 1, 8
        vector<bool> isExclude = {true, true, false, false, false, false, false, false, true, false};
        vector<bool> isValid = {true, true, true, false, false, true, true, false, true, true};
        
        string num = to_string(N);
        int len = num.length(), count = 0;        
        bool exclude = true;
        for(int i = 0, mul = len; i < len; i++, mul--) {
            if(num[i] == '0' && i != len - 1 )
                continue;
            int index = (i == len - 1) ? num[i] - '0': num[i] - '0' - 1;
            double c =  allPossibleCount[index] * pow(7, mul - 1);   
            double e =  exclude ? excludeNumCount[index] * pow(3, mul - 1) : 0; // # of numbers which only contain 0,1,8
            count += (c - e);
            if(!isValid[num[i] - '0'])
                break;
            exclude &= isExclude[num[i] - '0'];
        }
        return count;
    }
};
