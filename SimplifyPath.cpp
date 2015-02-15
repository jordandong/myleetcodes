/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

Hide Tags Stack String
*/

class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/'); // deal with the situation ... at tail, e.g. /abc/....
        int l = path.length();
        string spath;
        int dotCnt = 0;
        for(int i = 0; i < l; i++){
            if(path[i] == '/'){
                if(dotCnt > 2){ //... is a directory, add it
                    while(dotCnt != 0){
                        spath.push_back('.');
                        dotCnt--;
                    }
                }else if(dotCnt == 2){ // .. means the last folder, remove
                    spath.pop_back(); //pop one '/'
                    while(!spath.empty() && spath.back()!='/')
                        spath.pop_back();
                    dotCnt=0;
                }else if(dotCnt==1){
                    dotCnt=0;
                }
                
                if(spath.empty() || spath.back()!='/')
                    spath.push_back(path[i]);

            }else if(path[i]=='.'){// '.'
                dotCnt++; //must start with a '/'
            }else{ // abc
                while(dotCnt != 0){// if pattern like /.abc, /..abc, /...abc,  then add the dots
                    spath.push_back('.');
                    dotCnt--;
                }
                spath.push_back(path[i]); // add abc
                while(i + 1 < l && path[i + 1] == '.')//if pattern like /abc., /abc.., /abc...,  then add the dots
                    spath.push_back(path[++i]);
            }
        }
        
        if(spath.size() < 2)
            spath = "/";
        else if(spath.back() == '/')
            spath.pop_back();
        return spath;
    }
};
