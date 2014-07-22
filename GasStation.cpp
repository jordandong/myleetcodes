/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int size = gas.size();
        int total_gas_left = 0;
        int sub_gas_left = 0;
        int start = 0;
        for(int i=0; i<size; i++){
            int diff=gas[i]-cost[i];
            total_gas_left+=diff;
            sub_gas_left+=diff;
            if(sub_gas_left<0){
                sub_gas_left=0;
                start=i+1;
            }
        }
        if(total_gas_left<0)
            return -1;
        else
            return start;
    }
};


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size = gas.size();
        int start = 0;
        do{
            int left = 0;
            int k = start;
            int end = start;
            int flag = 0;
            do{
                if(0 <= left + gas[k]- cost[k]){
                    left = left + gas[k]-cost[k];
                    k=(k+1)%size;
                    flag = 1;
                }else{
                    start = k>=start ? k+1:size;
                    break;
                }
            }while(k!=end);
            if((k==end) && flag)
                return start;
        }while(start<size);
        return -1;
    }
};
