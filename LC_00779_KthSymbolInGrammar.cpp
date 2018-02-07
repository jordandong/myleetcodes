/*
On the first row, we write a 0.
Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001

Note:
1. N will be an integer in the range [1, 30].
2. K will be an integer in the range [1, 2^(N-1)].
*/

class Solution {
public:
    int kthGrammar(int N, int K) {
        //When N is increased by 1, the sequence extends by flipping itself, e.g. 0110 -> 0110 1001.
        // Those extended Ks are exactly the originals with a prefixing 1 in their binary representations, which exactly changes the parity of the number of 1s.
        //       0  1  1  0       1   0   0   1 
        //      00 01 10 11 - > 100 101 110 111
        //index  0  1  2  3       4   5   6   7
        //index at 4 is the result index at 0 plus one 1s, exactly the changes of prefixing 1s
        return bitset<32>(K - 1).count() % 2;
    }
};
