class Solution {
	public:
		vector<vector<int> > threeSum(vector<int> &num) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<vector<int> > res;

			if(num.size()<3)
				return res;

			int size = num.size();

			sort(num.begin(),num.end());

			for(int i=0;i<size-2;i++){
				if(num[i]>0)
					break;
				if (i > 0 && num[i] == num[i-1])  
					continue;

				int begin =i+1;
				int end = size-1;
				while(begin < end){
					int sum = num[i]+num[begin]+num[end]; 
					if(sum==0){
						if (num[begin] == num[begin-1] && begin > i+1){  
							begin = begin + 1;  
							continue;  
						}
						vector<int> tmp;
						tmp.push_back(num[i]);
						tmp.push_back(num[begin]);
						tmp.push_back(num[end]);
						res.push_back(tmp);
						begin++;
						end--;
					}
					else if (sum > 0)   
					{  
						end = end - 1;  
						if (num[end] == num[end+1]){  
							end = end - 1;  
						}  
					}  
					else  
					{  
						begin = begin + 1;  
						if (num[begin] == num[begin-1])  {  
							begin = begin + 1;  
						}  
					} 
				}
			}
			return res;
		}
};
