/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

Hide Tags Dynamic Programming String
*/

//Optimize the space use
class Solution {
public:
    int minDistance(string word1, string word2) {
        string* longStr = &word1;
        string* shortStr = &word2;
        if(word1.size() < word2.size())
            swap(longStr, shortStr);
        
        int * lastDP = new int[shortStr->size() + 1];   
        int* curDP = new int[shortStr->size() + 1];
        for(int i = 0; i<= shortStr->size(); i++){
            curDP[i] = 0;
            lastDP[i] = i;
        }
        
        for(int i = 1; i <= longStr->size(); i++){
            curDP[0] = i;
            for(int j = 1; j <= shortStr->size(); j++)
                curDP[j] = min( min(curDP[j-1], lastDP[j]) + 1,  lastDP[j-1] + ((*longStr)[i-1] != (*shortStr)[j-1]));
                //add , delete OR replace
            int* temp = curDP;
            curDP = lastDP;
            lastDP = temp;
        }
        int res = lastDP[shortStr->size()];
        delete lastDP;
        delete curDP;
        return res;
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        int c = 0;
        int dp[2][N+1];

        dp[c][0] = 0;
        for(int j = 1; j <= N; j++)
            dp[c][j] = j;

        for(int i = 1; i <= M; i++) {
            dp[c^1][0] = i;
            for(int j = 1; j <= N; j++)
                dp[c^1][j] = min(min(dp[c][j], dp[c^1][j-1]) + 1, dp[c][j-1] + (word1[i-1] != word2[j-1]));
            c ^= 1;
        }

        return dp[c][N];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        int dp[M+1][N+1];
        dp[0][0] = 0;
        for (int j = 1; j <= N; j++)
            dp[0][j] = j;

        for (int i = 1; i <= M; i++) {
            dp[i][0] = i;
            for (int j = 1; j <= N; j++) {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]) + 1, dp[i-1][j-1] + (word1[i-1] != word2[j-1]));
            }
        }

        return dp[M][N];
    }
};
