class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> subset;
        vector<vector<int> > res;
        sort(num.begin(),num.end());
        comsum(num,0,target, subset, res);
        return res;
    }
    
    
    bool comsum(vector<int> &data, int index, int tg, vector<int> &subset, vector<vector<int> > &res){
        if(tg==0)
            return true;
        if(tg<0||index>=data.size())
            return false;
        
        for(int i=index;i<data.size();i++){
            if(i>index&&data.at(i)==data.at(i-1))
                continue;
            subset.push_back(data.at(i));      
            if(comsum(data, i+1, tg-data.at(i), subset, res)){
                res.push_back(subset);
                subset.pop_back();
            }
            else{
                subset.pop_back();
            }
        }
        return false;
    }
};
