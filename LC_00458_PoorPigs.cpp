/*
There are 1000 buckets, one and only one of them contains poison, the rest are filled with water.
They all look the same. If a pig drinks that poison it will die within 15 minutes.
What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.

Answer this question, and write an algorithm for the follow-up general case.

Follow-up:
If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need to figure out the "poison" bucket within p minutes? There is exact one bucket with poison.
*/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int rounds =  minutesToTest / minutesToDie + 1;
        //each pig decides one digit, carry at rounds
        while (pow(rounds, pigs) < buckets)
            pigs++;
        return pigs;
    }
};

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets <= 0)
            return -1;
        if (buckets-- == 1)
            return 0;
        int states = minutesToTest / minutesToDie + 1;
        //states ^ count >= buckets, mini count
        int count = 0;
        while (buckets > 0){
            buckets /= states;
            count++;
        }
        return count;
    }
};
