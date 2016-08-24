/*
You are playing the following Bulls and Cows game with your friend: You write a 4-digit secret number and ask your friend to guess it, each time your friend guesses a number, you give a hint, the hint tells your friend how many digits are in the correct positions (called "bulls") and how many digits are in the wrong positions (called "cows"), your friend will use those hints to find out the secret number.

For example:
Secret number:  1807
Friend's guess: 7810
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)

According to Wikipedia: "Bulls and Cows (also known as Cows and Bulls or Pigs and Bulls or Bulls and Cleots) is an old code-breaking mind or paper and pencil game for two or more players, predating the similar commercially marketed board game Mastermind. The numerical version of the game is usually played with 4 digits, but can also be played with 3 or any other number of digits."
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows, in the above example, your function should return 1A3B.
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Hash Table
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> map_s(10, 0);
        vector<int> map_g(10, 0);
        int cnt_a = 0, cnt_b = 0;
        if (secret.length() != guess.length() || secret.length() == 0)
            return "0A0B";    	
        for (int i = 0; i < secret.length(); i++) {
            char s = secret[i];
            char g = guess[i];
            if (s == g) {
                cnt_a++;
            } else {
                map_s[s - '0']++;
                map_g[g - '0']++;
            }
        }

        for (int i = 0; i < 10; i++)
            cnt_b += min(map_s[i], map_g[i]);

        return to_string(cnt_a) + "A" + to_string(cnt_b) + "B";
    }
};
