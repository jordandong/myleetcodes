/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = num.size();
        unordered_set<int> mp;
        int max_count = 0;
	    for(int i=0; i<N; i++)
		    mp.insert(num[i]);

	    for(int i=0; i<N; i++){
		    if(mp.find(num[i])!=mp.end()){
			    int count = 1;
			    mp.erase(num[i]);
			    int key = num[i];
			    while(mp.find(++key)!=mp.end()){
				    count++;
				    mp.erase(key);
			    }

			    key=num[i];
			    while(mp.find(--key)!=mp.end()){
				    count++;
				    mp.erase(key);
			    }
			    max_count=count>max_count?count:max_count;
		    }
	    }
    return max_count;
    }
};
