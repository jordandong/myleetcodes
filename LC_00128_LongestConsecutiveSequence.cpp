/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

Hide Tags Array
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int N = num.size();
        unordered_set<int> mp;
        int max_count = 0;
        
        for(auto e : num)
            mp.insert(e);
        for(auto e : num){
            if(mp.find(e) != mp.end()){
                int count = 1;
                mp.erase(e);
                int key = e;
                while(mp.find(++key) != mp.end()){
                    count++;
                    mp.erase(key);
                }
                
                key = e;
                while(mp.find(--key) != mp.end()){
                    count++;
                    mp.erase(key);
                }
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
};
