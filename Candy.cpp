/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Hide Tags Greedy
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        int sz = ratings.size();
        if(sz <= 1)
            return sz;
    
        vector<int> assign(sz, 1);
        int sum = 0;
        
        for(int i = 1; i < sz; i++){
            if(ratings[i] > ratings[i-1])
                assign[i] = assign[i-1] + 1;
        }
        
        for(int j = sz - 2; j >= 0; j--){
            if(ratings[j] > ratings[j + 1] && assign[j] <= assign[j + 1])
                assign[j] = assign[j + 1] + 1;
        }

        for(int k =0; k < sz; k++)
            sum += assign[k];

        return sum;
    }
};
