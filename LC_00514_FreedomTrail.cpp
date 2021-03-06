/*
In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring",
and use the dial to spell a specific keyword in order to open the door.

Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled.
You need to find the minimum number of steps in order to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at 12:00 direction.
You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button. 
At the stage of rotating the ring to spell the key character key[i]:
1. You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
2. If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.

Example:
     G
  G     O
N    *    D
   I   D
Input: ring = "godding", key = "gd"
Output: 4
Explanation:
1. For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
2. For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
3. Also, we need 1 more step for spelling.
4. So the final output is 4.

Note:
1. Length of both ring and key will be in range 1 to 100.
2. There are only lowercase letters in both strings and might be some duplcate characters in both strings.
3. It's guaranteed that string key could always be spelled by rotating the string ring.

Hide Tags “Dynamic Programming” Depth-first Search Divide and Conquer
*/

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ans = INT_MAX, K = key.size(), R = ring.size();
        vector<vector<int>> dp(2, vector<int>(R, INT_MAX));
        for (int i = 0; i < K; i++) { // each char in key
            for (int j = 0; j < R; j++) { // each char in ring
                dp[i % 2][j] = INT_MAX;
                if (ring[j] == key[i]) { // ring char matches key char
                    if (i == 0) { //base dp case
                        dp[i % 2][j] = min(dp[i % 2][j], min(j, R - j));
                        continue;
                    }
                    for (int k = 0; k < R; k++) { // look up previous result
                        if (dp[(i - 1) % 2][k] != INT_MAX) { // find previous result
                            // update current result
                            dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][k] + min((k + R - j)%R, (j + R - k)%R));
                            if (i == K - 1)
                                ans = min(ans, dp[i % 2][j]); // if last row, update answer
                        }
                    }
                }
            }
        }
        return ans + K;
    }
};

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ans = INT_MAX, K = key.size(), R = ring.size();
        vector<vector<int>> dp(K, vector<int>(R, INT_MAX));
        for (int i = 0; i < K; i++) { // Go through every char in key
            for (int j = 0; j < R; j++) { // Go through every char in ring
                if (ring[j] == key[i]) { // ring char matches key char
                    if (i == 0) {
                        dp[i][j] = min(dp[i][j], min(j, R - j));
                        continue;
                    }
                    for (int k = 0; k < R; k++) { // look up previous result
                        if (dp[i - 1][k] != INT_MAX) { // find previous result
                            dp[i][j] = min(dp[i][j], dp[i - 1][k] + min((k + R - j)%R, (j + R - k)%R)); // update current state
                            if (i == K - 1)
                                ans = min(ans, dp[i][j]); // if last row, update answer
                        }
                    }
                }
            }
        }
        return ans + K;
    }
};
