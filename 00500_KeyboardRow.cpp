/*
Given a List of words,
return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

American keyboard

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
  		vector<int> mp = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
		vector<string> ans;
		for (auto & w : words) {
		    int last_row = mp[idx(w[0])], i = 1;
			while (i < w.size()) {
				if (mp[idx(w[i])] != last_row)
					break;
				i++;
			}
			if (i == w.size())
				ans.push_back(w);
		}
		return ans;
	}
private:
	int idx(char a) {
		if (a >= 'a' && a <= 'z')
			return a - 'a';
		else
		    return a - 'A';
	}
};
