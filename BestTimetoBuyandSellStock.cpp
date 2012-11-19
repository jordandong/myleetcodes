/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size()==0)
            return 0;
        vector<int> diff;
        for(int i=0;i<prices.size()-1;i++)
        {
            diff.push_back(prices[i+1]-prices[i]);
        }
        
        int sum =0;
        int max =0;
        for(int j=0;j<diff.size();j++)
        {
            if(sum+diff[j]>0)
                sum+=diff[j];
            else
                sum=0;
                
            if(sum>max)
                max =sum;
        }
        
        return max;
    }
};
