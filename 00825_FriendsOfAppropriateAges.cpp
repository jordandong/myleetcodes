/*
Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person. 

Person A will NOT friend request person B (B != A) if any of the following conditions are true:

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

How many total friend requests are made?

Example 1:

Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.
Example 2:

Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
Example 3:

Input: [20,30,100,110,120]
Output: 
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
 

Notes:

1 <= ages.length <= 20000.
1 <= ages[i] <= 120.
*/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        //B is in range ( 0.5 * A + 7, A ]
        int age[121] = {}, res = 0;
        for (auto a : ages)
            ++age[a];
        for (auto A = 15; A < 121; ++A) {
            for (int B = 0.5 * A + 8; B <= A; ++B) {
                res += age[B] * (age[A] - (A == B));
            }
        }
        return res;    
    }
};

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        //B is in range ( 0.5 * A + 7, A ]
        int age[121] = {}, res = 0;
        for (auto a : ages)
            ++age[a];
        for (auto A = 15, minAge = 15, sSum = 0; A < 121; sSum += age[A], res += age[A++] * (sSum - 1)) {
            while (minAge <= 0.5 * A + 7)
                sSum -= age[minAge++];
        }
        return res;
    }
};

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        //B is in range ( 0.5 * A + 7, A ]
        int age[121] = {}, sum_age[121] = {0}, res = 0;
        for (auto a : ages)
            ++age[a];
        for (int i = 1; i < 121; i++)
            sum_age[i] = sum_age[i - 1] + age[i];
        for (auto A = 15; A < 121; A++) {
            if (age[A])
                res += (sum_age[A] - sum_age[A / 2 + 7] - 1/*self*/) * age[A];
        }
        return res;
    }
};
