class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min = 2147483647;
        int res;
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int size = num.size();
		sort(num.begin(),num.end());

        for(int i=0;i<size-2;i++){

			int begin =i+1;
			int end = size-1;
			while(begin < end){
				int sum = num[i]+num[begin]+num[end]-target;
				int tsum = abs(sum);
                if(tsum<min){
					min = tsum;
                    res = sum + target;
				}
                
                if(sum==0)
                    return res;
                    
				if (sum > 0)   
				{  
					end = end - 1;   
				}  
				else if(sum <0)  
				{  
					begin = begin + 1;  
		
				} 
			}
		}
		return res;    
    }
};
