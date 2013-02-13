/*Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
*/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int size=dict.size();
        int res=1;
        stack<string> stk[2];
        unordered_set<string> used;
        int index=0;
        stk[index%2].push(start);
        used.insert(start);
        
        while(!stk[index%2].empty()){
            if(res == size+2)
                return 0;
            string current=stk[index%2].top();
            stk[index%2].pop();
            int N=current.length();
            for(int i=0;i<N;i++){
               for(char s='a';s<='z';s++){
                    if(current[i]!=s){
                        string tmp = current;
                        tmp[i]=s;
                        if(!tmp.compare(end)){
                            res++;
                            return res;
                        }
                    
                        if(dict.find(tmp)!=dict.end()&&used.find(tmp)==used.end()){
                            stk[(index+1)%2].push(tmp);
                            used.insert(tmp);
                        }
                    }
                }
            }
            if(stk[index%2].empty()){
                index=index+1;
                res++;
            }
        }
        return 0;
    }
};
