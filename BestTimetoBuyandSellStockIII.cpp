//============================================================================
// Best Time to Buy and Sell Stock
// 
// Say you have an array for which the ith element is the price of a given 
// stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most 
// two transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must 
// sell the stock before you buy again).
//
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int N = prices.size();
        if (N <= 1)
        	return 0;
        int min_val = prices[0];
        vector<int> left(N, 0);
        for (int i = 1; i < N; ++i)
        {
            if (prices[i] < min_val)
            	min_val = prices[i];
            left[i] = max(left[i-1], prices[i]-min_val);
        }
        int max_val = prices[N-1];
        vector<int> right(N, 0);
        for (int i = N-2; i >= 0; --i)
        {
            if (prices[i] > max_val)
            	max_val = prices[i];
            right[i] = max(right[i+1], max_val-prices[i]);
        }
        int res = 0;
        for (int i = 0; i < N; ++i)
            res = max(res, left[i]+right[i]);
        return res;
    }
};

int main()
{
    return 0;
}





class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size()<=1)
            return 0;
        
        vector<int> diff;
        for(int i=0;i<prices.size()-1;i++)
        {
            diff.push_back(prices[i+1]-prices[i]);
        }
        
        int posi =0;
        int nega =0;
        vector<int> inter;
        for(int j=0;j<diff.size();j++)
        {
            if(diff[j]>0){
                if(nega<0){
                    inter.push_back(nega);
                    nega=0;
                }
                posi+=diff[j];
            }
            else if(diff[j]<0){
                if(posi>0){
                    inter.push_back(posi);
                    posi=0;
                }
                nega+=diff[j];
            }
        }
        
        if(nega<0){
            inter.push_back(nega);
            nega=0;
        }
        if(posi>0){
            inter.push_back(posi);
            posi=0;
        }
        
        int len = inter.size();
        if (len==0)
            return 0;
        
        int maxb =0;
        if(inter[0]>0){
            if(len==1)
                return inter[0];
            for(int i=1;i<len;i+=2){
                maxb=max(cal(inter, i),maxb);
            }
        }else{
            if(len==1)
                return 0;
            for(int i=0;i<len;i+=2){
                maxb=max(cal(inter, i),maxb);
            }            
        }
        
        return maxb;
    }
    
    
    int cal(vector<int> &inter, int index) {
        int left=0;
        int right =0;
        int suml =0;
        int sumr=0;
        for(int i =0;i<index;i++)
        {
            if(suml+inter[i]>0){
                suml+=inter[i];
                if(suml>left)
                    left=suml;
            }
            else
                suml=0;
        }
        
        for(int i =index;i<inter.size();i++)
        {
            if(sumr+inter[i]>0){
                sumr+=inter[i];
                if(sumr>right)
                    right=sumr;
            }
            else
                sumr=0;
        }
        
        return left+right;   
    }
};


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size()==0||prices.size()==1)
            return 0;
            
        int len=prices.size();
        int* dp1=new int[len];
        int* dp2=new int[len];
        for(int i=0;i<len;i++){
            dp1[i]=0;
            dp2[i]=0;
        }
        int smax=prices[len-1];
        int smin=prices[0];
        //first i days, buy max
        for(int i=1;i<len;i++)
        {
            smin=min(smin,prices[i]);
            dp1[i]=max(dp1[i-1],prices[i]-smin);
        }
        //from i days, buy max
        for(int i=len-2;i>=0;i--)
        {
            smax=max(smax, prices[i]);
            dp2[i]=max(dp2[i+1],smax-prices[i]);
        }
        
        //before i day + after i day
        int ans=0;
        for(int i=0;i<len;i++)
            ans=max(ans, dp1[i]+dp2[i]);
        return ans;
    }
};

