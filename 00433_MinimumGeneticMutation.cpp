/*
A gene string can be represented by an 8-character long string, with choices from "A","C","G","T". 
Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string. 
For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation. 
Also, there is a given gene "bank", which records all the valid gene mutations.
A gene must be in the bank to make it a valid gene string. 

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". 
If there is no such a mutation, return -1. 

For example, 
bank: "AACCGGTA" 
start: "AACCGGTT" 
end: "AACCGGTA" 
return: 1

bank: "AACCGGTA", "AACCGCTA", "AAACGGTA"
start: "AACCGGTT"
end: "AAACGGTA"
return: 3
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int res = -1;
        unordered_set<string> m(bank.begin(), bank.end());
        queue<string> q;

        if (start.length() != end.length())
            return res;
        if (m.count(end) == 0)
            return res;
        if (start == end)
            return 0;
        
        q.push("#");
        q.push(start);
        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (cur == "#") {
                if (!q.empty()) {
                    q.push("#");
                    res++;
                }
                continue;
            }
            
            if (cur == end)
                return res;

            for (int i = 0; i < (int)cur.size(); ++i) {
                char t = cur[i];
                for (char &c : string("ACTG")) {
                    if (t != c) {
                        cur[i] = c;
                        if (m.count(cur)) {
                            q.push(cur);
                            m.erase(cur);
                        }
                    }
                }
                cur[i] = t;
            }
        }
        return -1;
    }
};
