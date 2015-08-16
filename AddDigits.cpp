/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:
A naive implementation of the above process is trivial. Could you come up with other methods?
1. What are all the possible results?
2. How do they occur, periodically or randomly?
3. You may find this Wikipedia article useful.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Tags Math
*/

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
