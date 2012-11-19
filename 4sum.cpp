class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;

		if(num.size()<4)
			return res;

		int size = num.size();

		sort(num.begin(),num.end());

		for(int j=0;j<size-3;j++){
            if(j>0&&num[j]==num[j-1])
    		    continue;
                
            for(int i = j+1;i<size-2;i++){
			    if(i>j+1&&num[i]==num[i-1])
    		        continue;
                    
                int begin =i+1;
			    int end = size-1;
			    while(begin < end){
				    int sum =num[j]+num[i]+num[begin]+num[end];
				    if(sum==target){
                        if (num[begin] == num[begin-1] && begin > i+1){  
							begin++;  
							continue;  
						}
					    vector<int> tmp;
                        tmp.push_back(num[j]);
					    tmp.push_back(num[i]);
					    tmp.push_back(num[begin]);
					    tmp.push_back(num[end]);
					    res.push_back(tmp);
                        
                        begin++;
                        end--;
				    }
				    else if(sum > target){ 
                        end--;
                        while (num[end] == num[end+1]){  
							end--;  
						}  
				    }  
				    else{
                        begin++;
					    while(num[begin] == num[begin-1]){  
							begin++;  
						}  
					}
				}
			}
		}
		return res;
    }
};
