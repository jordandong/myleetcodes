//============================================================================
// SimplifyPath
// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together,
// such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".
//============================================================================

class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/'); // deal with the situation ... at tail, e.g. /abc/....
        int size = path.length();
        string spath;
        int dotCnt=0;
        for(int i=0; i<size;i++){
            if(path[i]=='/'){
                if(dotCnt>2){ //... is a directory, add it
                    while(dotCnt!=0){
                        spath.push_back('.');
                        dotCnt--;
                    }
                }else if(dotCnt==2){ // .. means the last folder, remove
                    spath.pop_back();//pop one '/'
                    while(!spath.empty()&&spath.back()!='/')
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
                while(dotCnt!=0){// if pattern like /.abc, /..abc, /...abc,  then add the dots
                    spath.push_back('.');
                    dotCnt--;
                }
                spath.push_back(path[i]); // add abc
                while(i+1<size && path[i+1]=='.')//if pattern like /abc., /abc.., /abc...,  then add the dots
                    spath.push_back(path[++i]);
            }
        }
        
        if(spath.size()<2)
            spath="/";
        else if(spath.back()=='/'){
            spath.pop_back();
        }
        return spath;
    }
};



class Solution {
public:
    string simplifyPath(string path) {
        int N = path.size();
        if (N <= 1)
            return path;
        string res;
        for (int i = 0; i < N; i++) {
            char c = path[i];
            if (c == '/') {
                if (res.empty() || res[res.size()-1] != '/')
                    res.push_back(path[i]);
            }
            else if (c == '.') {
                if (i+1 < N && path[i+1] == '.') {
                    i++;
                    res.erase(res.size()-1,1);
                    while (!res.empty()) {
                        if (res[res.size()-1] != '/')
                        	res.erase(res.size()-1,1);
                        else
                        	break;
                    }
                }
            }
            else {
                res.push_back(path[i]);
            }
        }
        if (res.size() < 2)
        	return "/";
        if (res[res.size()-1] == '/')
        	res.erase(res.size()-1,1);
        return res;
    }
};


class Solution {
public:
    string simplifyPath(string path) {
        int N = path.size();
        if (N <= 1)
        	return path;
        deque<char> buffer;
        for (int i = 0; i < N; i++) {
            char c = path[i];
            if (c == '/') {
                if (buffer.empty() || buffer.back() != '/')
                    buffer.push_back(path[i]);
            }
            else if (c == '.') {
                if (i+1 < N && path[i+1] == '.') {
                    i++;
                    buffer.pop_back();
                    while (!buffer.empty()) {
                        if (buffer.back() != '/')
                        	buffer.pop_back();
                        else
                        	break;
                    }
                }
            }
            else {
                buffer.push_back(path[i]);
            }
        }
        if (buffer.size() < 2)
        	return "/";
        if (buffer.back() == '/')
        	buffer.pop_back();
        
        string res;
        while (!buffer.empty()) {
            res.push_back(buffer.front());
            buffer.pop_front();
        }
        return res;
    }
};
