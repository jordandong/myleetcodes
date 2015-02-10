/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Hide Tags Hash Table Two Pointers String
*/

//brute force T: O(M*N*K)  S:O(N*K)
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
    	map<string, int> toFind;
    	map<string, int> hasFound;
    	vector<int> res;
    	int M = S.size();
    	int N = L.size();
    	int K = L[0].size();
    	
    	for(int i = 0; i < N; i++)
	    toFind[L[i]]++;
	    
	for (int i = 0; i <= M - N*K; i++) {
	    hasFound.clear();
	    int j = 0;
	    for (j = 0; j < N; j++) {
	    	int p = i + j * K;
	    	string sub = S.substr(p, K);
	    	if (toFind.find(sub) == toFind.end())
	    	    break;
	    	hasFound[sub]++;
	    	if (hasFound[sub] > toFind[sub])
	    	    break;
	    }
	    if (j == N)
	        res.push_back(i);
	}
	return res;
    }
};
