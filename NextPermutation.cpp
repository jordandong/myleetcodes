/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

Hide Tags Array
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int N = num.size();
        if (N < 2)
        	return;
        int i = N - 2;
        while (i >= 0 && num[i] >= num[i+1])
        	i--;
        
        if (i == -1) {
            reverse(num.begin(), num.end());
            return;
        }
               
        int j = N-1;
        while (j > i && num[j] <= num[i])
        	j--;
        	
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());
    };
};
