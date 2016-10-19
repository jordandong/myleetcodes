/*
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available.
You need to determine whether it is possible to measure exactly z litres using these two jugs.

Operations allowed:
Fill any of the jugs completely.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

Example 1:
Input: x = 2, y = 6, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False

Hide Tags Math
*/

//x = md, y = nd, z = kd,  amd - bnd = kd -> am - bn = k
//there exists ax + (-by) = t (t = 0 , t = 1), then t + 1 = a'x + (-b'y) exsits, then t = [1 ~ (x + y)] exists 
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        int d = GCD(x, y);
        return d == z || ((z <= x + y) && (z % d == 0));
    }
    
    int GCD(int x, int y) {
        return x ? GCD(y%x, x) : y;
    }
};
