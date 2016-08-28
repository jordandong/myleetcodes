/*
There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Find the last number that remains starting with a list of length n.

Example:
Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
*/

//T : O(logN), S : O(1)
class Solution {
public:
    int lastRemaining(int n) {
        int begin = 1,  step = 1, round = 0;
        int end;
        while (n > 1) {
            n /= 2;
            round++;
            step *= 2;
            if (round % 2) {//left to right
                end = begin + step/2 + step * (n - 1);
            } else { //right to left
                end = begin - step/2 - step * (n - 1);
            }
            begin = end;
        }
        return begin;
    }
};
