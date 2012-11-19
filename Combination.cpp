class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> sub;
        vector<vector<int> > res;
        comb(n,1,k,sub,res);
        return res;
    }
    
    bool comb(int n, int start, int k, vector<int> &sub, vector<vector<int> > &res){
        if(k==0)
            return true;
            
        for(int i=start; i<=n; i++){
            sub.push_back(i);
            if(comb(n,i+1,k-1,sub,res)){
                res.push_back(sub);
                sub.pop_back();
            }else{
                sub.pop_back();
            }  
        }
        return false;
    }
};
