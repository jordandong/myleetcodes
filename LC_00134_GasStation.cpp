/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Hide Tags Greedy
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sz = gas.size();
        int total_gas_left = 0;
        int sub_gas_left = 0;
        int start = 0;
        for(int i = 0; i < sz; i++){
            int diff = gas[i] - cost[i];
            total_gas_left += diff;
            sub_gas_left += diff;
            if(sub_gas_left < 0){
                sub_gas_left = 0;
                start = i + 1;
            }
        }
        return total_gas_left < 0 ? -1 : start;
    }
};
