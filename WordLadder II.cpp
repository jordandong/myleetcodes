/*Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size=dict.size();
        int res=1;
        int done=0;
        stack<string> stk[2];
        unordered_set<string> used;
        unordered_map<string, vector<string> > path;
        unordered_set<string> level;
        int index=0;
        stk[index%2].push(start);
        used.insert(start);
        vector<vector<string>> rtn;
        
        while(!stk[index%2].empty()&&done!=2){
            if(res == size+2)
                return rtn;
            string current=stk[index%2].top();
            stk[index%2].pop();
            int N=current.length();
            for(int i=0;i<N;i++){
               for(char s='a';s<='z';s++){
                    if(current[i]!=s){
                        string tmp = current;
                        tmp[i]=s;
                        
                        if(dict.find(tmp)!=dict.end()||!tmp.compare(end)){
                            if(path.find(tmp)==path.end()){
                                path[tmp]=vector<string> (1,current);
                                level.insert(tmp);
                            }else{
                                if(level.find(tmp)!=level.end())
                                    path[tmp].push_back(current);
                            }
                            if(!tmp.compare(end))
                                done=1;
                            else if(used.find(tmp)==used.end()){
                                stk[(index+1)%2].push(tmp);
                                used.insert(tmp);
                            }
                        }
                    }
                }
            }
            if(stk[index%2].empty()){
                index=index+1;
                res++;
                level.clear();
                if(done)
                    done=2;
            }
        }
        if(done)
            getpath(start, end, path, rtn, vector<string>(0,"a"));
        return rtn;
    }
    
    void getpath(string start, string end, unordered_map<string, vector<string> > &path, vector<vector<string> > &rtn, vector<string> route){
        if(!start.compare(end)&&route.size()!=0){
            route.push_back(end);
            reverse(route.begin(), route.end());
            rtn.push_back(route);
            return;
        }
        
        vector<string> up = path[end];
        route.push_back(end);
        for(int i=0; i<up.size(); i++){
            getpath(start, up[i], path, rtn, route);
        }
    }
};
