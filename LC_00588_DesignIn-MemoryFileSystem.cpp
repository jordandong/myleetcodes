/*
Design an in-memory file system to simulate the following functions:
ls: Given a path in string format. If it is a file path, return a list that only contains this file's name.
    If it is a directory path, return the list of file and directory names in this directory.
    Your output (file and directory names together) should in lexicographic order.
mkdir: Given a directory path that does not exist, you should make a new directory according to the path.
    If the middle directories in the path don't exist either, you should create them as well.
    This function has void return type.
addContentToFile: Given a file path and file content in string format.
    If the file doesn't exist, you need to create that file containing given content.
    If the file already exists, you need to append given content to original content. This function has void return type.
readContentFromFile: Given a file path, return its content in string format.

Example:
Input: 
["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
Output:
[null,[],null,null,["a"],"hello"]
Explanation:
Operation                                   Output   Explanation
FileSystem fs = new FileSystem()            null     The constructor returns nothing
fs.ls("/")                                  []       Initially, directory / has nothing. So return empty list.
fs.mkdir("/a/b/c")                          null     Create directory a in directory /. Then create directory b in directory a. Finally , create directory c in directory b.
fs.addContentToFile("/a/b/c/d", "hello")    null     Create a file named d with content "hello" in directory /a/b/c.
fs.ls("/")                                  ["a"]    Only directory a is in directory /.
fs.readContentFromFile("/a/b/c/d")          "hello"  Output the file content.

Note:
1. You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
2. You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
3. You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.

Hide Tags Design
*/

class FileSystem {
public:
    #define DR 0
    #define FL 1
    typedef struct inode {
        int i;
        int type;
    } inode;

    FileSystem() {
        dirs.push_back({});
    }
    
    vector<string> ls(string path) {
        string dir;
        stringstream ss(path.substr(1));
        int i = 0;

        while (getline(ss, dir, '/')) {
            if (dirs[i].count(dir)) {
                int type = dirs[i][dir].type;
                if (type == FL) {
                    return {dir};
                } else {
                    i = dirs[i][dir].i;
                }
            }
        }
        
        vector<string> res;
        for (auto e : dirs[i]) {
            res.push_back(e.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {
        string dir;
        char delim;
        stringstream ss(path.substr(1));
        int i = 0;
        while (getline(ss, dir, '/')) { //root alwasy at index 0
            if (!dirs[i].count(dir)) {
                int n = dirs.size();
                dirs.push_back({});
                dirs[i].insert({dir, {n, DR}});
            }
            i = dirs[i][dir].i;
        }
       
    }
    
    void addContentToFile(string filePath, string content) {
        string dir;
        stringstream ss(filePath.substr(1));
        int i = 0;
        while (getline(ss, dir, '/')) {
            if (dirs[i].count(dir)){
                if(dirs[i][dir].type == DR)
                     i = dirs[i][dir].i;
                else
                    files[dirs[i][dir].i] += content;
            } else {
                int n = files.size();
                files.push_back(content);
                dirs[i][dir] = {n, FL};
            }
        }
       
    }
    
    string readContentFromFile(string filePath) {
        string dir;
        stringstream ss(filePath.substr(1));
        int i = 0;
        string res;
        while (getline(ss, dir, '/')) {
            if (dirs[i][dir].type == DR){
                i = dirs[i][dir].i;
            } else {
                res = files[dirs[i][dir].i];
            }
        }
        return res;
    }
private:
    vector<unordered_map<string,inode>> dirs;
    vector<string> files;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
