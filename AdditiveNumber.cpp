/*
Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Have you met this question in a real interview? Yes No
*/

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int N = num.size();
        for(int i = 1; i <= N/2; i++)
            for(int j = 1; j <= (N - i)/2; j++)
                if(isAdditiveNumberCheck(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                    return true;
        return false;
    }

    bool isAdditiveNumberCheck(string num1, string num2, string num){
        int size1 = num1.length();
        int size2 = num2.length();
        int size = num.length();
        if (size1 == 0 || (size1 != 1 && num1[0] == '0'))
            return false;
        if (size2 == 0 || (size2 != 1 && num2[0] == '0'))
            return false;
        if (size == 0 || (size != 1 && num[0] == '0'))
            return false;

        string sum = isAdditiveNumberAdd(num1, num2);
        if(num == sum)
            return true;
        if(size <= sum.size() || sum.compare(num.substr(0, sum.size())) != 0)
            return false;
        else
            return isAdditiveNumberCheck(num2, num.substr(0, sum.size()), num.substr(sum.size()));
    }

    string isAdditiveNumberAdd(string n1, string n2){
        string res;
        int l1 = n1.size() - 1;
        int l2 = n2.size() - 1;
        int carry = 0;
        while(l1 >= 0 || l2 >= 0){
            int sum = carry + (l1 >= 0 ? (n1[l1--] - '0') : 0) + (l2 >= 0 ?  (n2[l2--] - '0') : 0);
            res.push_back(sum % 10 + '0');
            carry = sum/10;
        }

        if(carry)
            res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
