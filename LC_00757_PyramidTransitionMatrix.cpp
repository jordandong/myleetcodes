/*
We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`.
We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

We start with a bottom row of bottom, represented as a single string.
We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:
Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  D   E
 / \ / \
X   Y   Z
This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.

Example 2:
Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.

Note:
1. bottom will be a string with length in range [2, 8].
2. allowed will have length in range [0, 200].
3. Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
*/

/*
Intuition and Algorithm
We model the states that blocks can be in. Each state is a binary number where the kth bit is set if the kth type of block is a possibility.
Then, we create a transition map T[state1][state2] -> state that takes a left state and a right state and outputs all possible parent states.

At the end, applying these transitions is straightforward.
However, this approach is not correct, because the transitions are not independent.
If for example we have states in a row A, {B or C}, A, and allowed triples (A, B, D), (C, A, D),
then regardless of the choice of {B or C} we cannot create the next row of the pyramid.

"ABCD"
["BCE","BCF","ABA","CDA","AEG","FAG","GGG"]
A EF A
AE and FA cannot happened together
*/

//DFS trying all combinations 
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        set<int> v;
        int N = bottom.length();
        vector<vector<int>> state(7, vector<int>(7, 0));
        vector<vector<int>> pyr(N, vector<int>(N, 0));

        int t = 0;
        for (string s: allowed)
            state[s[0] - 'A'][s[1] - 'A'] |= ( 1 << (s[2] - 'A'));

        for (int i = 0; i < N; i++)
            pyr[N - 1][i] = bottom[i] - 'A';
        return pyramidTransitionHelper(pyr, 0, N - 1, 0, state, v);
    }

private:
    //pyr[i] - the ith row of the pyramid
    //R - integer representing the current row of the pyramid
    //N - length of current row we are calculating
    //i - index of how far in the current row we are calculating
    //Returns true iff pyramid can be built
    bool pyramidTransitionHelper(vector<vector<int>> &pyr, int R, int N, int i, vector<vector<int>> & state, set<int> &v) {
        if (N == 0)
            return true;
        if (i == N) {
            if (v.find(R) != v.end())
                return false; // If we've already tried this row, give up
            v.insert(R); // Add row to cache
            return pyramidTransitionHelper(pyr, 0, N - 1, 0, state, v); // Calculate next row
        } else {
            // w's jth bit is true iff block #j could be
            // a parent of pyr[N][i] and pyr[N][i+1]
            int w = state[pyr[N][i]][pyr[N][i + 1]];
            // for each set bit in w...
            for (int b = 0; b < 7; ++b) {
                if (((w >> b) & 1) != 0) {
                    pyr[N - 1][i] = b; //set parent to be equal to block #b
                    //If rest of pyramid can be built, return true
                    //R represents current row, now with ith bit set to b+1 in base 8.
                    if (pyramidTransitionHelper(pyr, R * 8 + (b + 1), N, i + 1, state, v))
                        return true;
                }
            }
            return false;
        }
    }
};
