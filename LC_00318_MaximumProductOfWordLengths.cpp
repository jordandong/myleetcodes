/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

Follow up:
Could you do better than O(n^2), where n is the number of words?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Tags Bit Manipulation
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> bmp(len, 0);
        int mlen = 0;
        //sort the vector from longest to shortest
        sort(words.begin(), words.end(), compare);
        for (int i = 0; i < len; i++){ //bit manipulation
            for(int j = 0; j < words[i].length(); j++) {
                bmp[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        for(int i = 0; i < len; i++){
            int wl_i = words[i].length();
            if (wl_i * wl_i <= mlen)
                break;
            for(int j = i + 1; j < len; j++){
                int wl_j = words[j].length();
                if (wl_i * wl_j <= mlen)
                    break;
                if ((bmp[i] & bmp[j]) == 0)
                    mlen = wl_i * wl_j;
            }
        }
        return mlen;
    }
    static bool compare(string a, string b){
        return a.length() > b.length();
    }
};
