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



class Solution {
public:
	typedef unordered_multimap<string, string> Map;
	typedef pair<Map::iterator,Map::iterator> PairIter;
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict){
		Map map, map2;
		queue<string> q, q2;
		q.push(start);
		bool goal = false;
		while (!q.empty()) {
			string word = q.front();
			q.pop();
			for (int i = 0; i < start.length(); i++) {
				string s = word;
				for (char c = 'a'; c <= 'z'; c++) {
					s[i] = c;
					if (s == word)
						continue;
					if (s == end)
						goal = true;
					if (map.find(s) == map.end() && dict.find(s) != dict.end()){
						if (map2.find(s) == map2.end()) {
								q2.push(s);
						}
						map2.insert(make_pair(s, word));
					}
				}
			}
			if (q.empty()) {
				swap(q, q2);
				map.insert(map2.begin(), map2.end());
				map2.clear();
				if(goal)
					return print(map, end, start);
				}
			}
			return vector<vector<string>>();
		}

	// backtrack to reconstruct the path from start -> end.
	vector<vector<string>> print(Map &map, string s, string start, int depth=0) {
		if (depth > 0 && s == start) {
			return vector<vector<string>>(1, vector<string>(1, s));
		}
		vector<vector<string>> ret;
		for (PairIter it = map.equal_range(s); it.first != it.second; ++it.first) {
			vector<vector<string>> temp = print(map, it.first->second, start, depth+1);
			for (int i = 0; i < temp.size(); i++) {
				temp[i].push_back(s);
			}
			ret.insert(ret.end(), temp.begin(), temp.end());
		}
		return ret;
	}
};


//will do it when availiable
class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict){
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        vector<vector<string> > rtn;
        unordered_map<string, vector<string>> used;
        unordered_map<string, vector<string>> used2;
        used[start].push_back(" ");
        queue<string> q[2];
        q[0].push(start);
        bool found = false;
        
        while(!q[0].empty()){
            string current = q[0].front();
            q[0].pop();
            
            int N = current.length();
            for(int i=0; i<N; i++){
               for(char s='a';s<='z';s++){
                    if(current[i]!=s){
                        string tmp = current;
                        tmp[i]=s;
                        if(!tmp.compare(end)){
                            found = true;
                            continue;
                        }
                        if(dict.find(tmp)!=dict.end() && used.find(tmp)==used.end()){
                            if (uesd2.find(tmp) == used2.end()) {
								q[1].push(tmp);
						    }
						    used2[tmp].push_back(current);
                        }
                    }
                }
            }
            if(q[0].empty()){
                if(found)
                    break;
                for(auto &it:used2){
                    for(int i=0; i<it.second.size();i++){
                        used[it.first].push_back(it.second[i]);
                    }
                }
                used2.clear();
                swap(q[0], q[1]);
            }
        }
        
        //addPath()
        return rtn;
	}
	
	//need a recurstion to find all the path
	void addPath(vector<vector<string> >& rtn, unordered_map<string, vector<string> > &used, string &start, string &end, string cur){
	    vector<string> path;
	    path.push_back(end);
	    while(cur.compare(start)){
	        path.push_back(cur);
            for(int i=0; i<used[cur].second.size();i++){
                cur=used[cur][i];
            }
	    }
	    path.push_back(start);
	    reverse(path.begin(), path.end());
	    rtn.push_back(path);
	}
};
