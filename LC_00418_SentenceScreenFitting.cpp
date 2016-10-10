/*
Given a rows x cols screen and a sentence represented by a list of words, find how many times the given sentence can be fitted on the screen.

Note:
1. A word cannot be split into two lines.
2. The order of words in the sentence must remain unchanged.
3. Two consecutive words in a line must be separated by a single space.
4. Total words in the sentence won't exceed 100.
5. Length of each word won't exceed 10.
6. 1 ≤ rows, cols ≤ 20,000.

Example 1:
Input:
rows = 2, cols = 8, sentence = ["hello", "world"]
Output: 
1
Explanation:
hello---
world---
The character '-' signifies an empty space on the screen.

Example 2:
Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]
Output: 
2
Explanation:
a-bcd- 
e-a---
bcd-e-
The character '-' signifies an empty space on the screen.

Example 3:
Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]
Output: 
1
Explanation:
I-had
apple
pie-I
had--
The character '-' signifies an empty space on the screen.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> wc(sentence.size());
        unordered_map<int, int> dp; //start idx -> row id
        for (int i = 0; i < sentence.size(); ++i) {
            wc[i] = wordsFit(sentence, i, cols); //start with index i, the wc on this row
        }

        int words = 0, start = 0;
        for (int i = 0; i < rows; ++i) {
            if (dp.find(start) != dp.end()) {
                int loops = (rows - i + 1)/(i - dp[start]);
		words += sentence.size() * loops;
		i += (i - dp[start]) * loops - 1;
		dp.clear();
            } else {
                words += wc[start];
                dp[start] = i;
                start = (start + wc[start]) % sentence.size();
            }
        }
        return words / sentence.size();
    }

private:
    int wordsFit(const vector<string>& sentence, int start, int cols) {
        if (sentence[start].length() > cols) {
            return 0;
        }

        int sum = sentence[start].length(), count = 1;
        for (int i = (start + 1) % sentence.size();
             sum + 1 + sentence[i].length() <= cols;
             i = (i + 1) % sentence.size()) {
            sum += 1 + sentence[i].length();
            ++count;
        }
        return count;
    }
};

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> wc(sentence.size());
        for (int i = 0; i < sentence.size(); ++i) {
            wc[i] = wordsFit(sentence, i, cols);
        }

        int words = 0, start = 0;
        for (int i = 0; i < rows; ++i) {
            words += wc[start];
            start = (start + wc[start]) % sentence.size();
        }
        return words / sentence.size();
    }

private:
    int wordsFit(const vector<string>& sentence, int start, int cols) {
        if (sentence[start].length() > cols) {
            return 0;
        }

        int sum = sentence[start].length(), count = 1;
        for (int i = (start + 1) % sentence.size();
             sum + 1 + sentence[i].length() <= cols;
             i = (i + 1) % sentence.size()) {
            sum += 1 + sentence[i].length();
            ++count;
        }
        return count;
    }
};

class Solution {
public:
  int wordsTyping(vector<string> &sentence, int rows, int cols) {
    int i = 0, j = 0, k = 0, times = 0;
    while (i < rows && j < cols) {
      if (sentence[k].length() > cols)
        break;
        int remain = cols - j;
        if (remain == sentence[k].length() + 1 || remain == sentence[k].length()) {
          k ++;
          j = 0;
          i++;
        } else if (remain < sentence[k].length()) {
          j = 0;
          i++;
        } else {
          j += (sentence[k].length() + 1);
          k++;
        }
      if (k == sentence.size()) {
        k = 0;
        times++;
      }
    }
    return times;
  }
};

int main() {
	vector<string> data = {"hello", "world"};
	Solution s;
	cout<<s.wordsTyping(data, 2 , 8)<<endl;
	data = {"a", "bcd", "e"};
	cout<<s.wordsTyping(data, 3 , 6)<<endl;
	data = {"I", "had", "apple", "pie"};
	cout<<s.wordsTyping(data, 4 , 5)<<endl;
	cout<<s.wordsTyping(data, 8 , 5)<<endl;
	cout<<s.wordsTyping(data, 9 , 5)<<endl;
	cout<<s.wordsTyping(data, 39 , 5)<<endl;	
	return 0;
}
