/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Divide and Conquer Array Bit Manipulation
*/

/*
Runtime: O(N^2) — Brute force solution: Check each element if it is the majority element.
Runtime: O(N), Space: O(N) — Hash table: Maintain a hash table of the counts of each element, then find the most common one.
Runtime: O(N*logN) — Sorting: Find the longest contiguous identical element in the array after sorting.
Average runtime: O(N), Worst case runtime: Infinity — Randomization: Randomly pick an element and check if it is the majority element. If it is not, do the random pick again until you find the majority element. As the probability to pick the majority element is greater than 1/2, the expected number of attempts is < 2.
Runtime: O(N*logN) — Divide and conquer: Divide the array into two halves, then find the majority element A in the first half and the majority element B in the second half. The global majority element must either be A or B. If A == B, then it automatically becomes the global majority element. If not, then both A and B are the candidates for the majority element, and it is suffice to check the count of occurrences for at most two candidates. The runtime complexity, T(n) = T(n/2) + 2n = O(n log n).
Runtime: O(N) — Moore voting algorithm: We maintain a current candidate and a counter initialized to 0. As we iterate the array, we look at the current element x:
If the counter is 0, we set the current candidate to x and the counter to 1.
If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
After one pass, the current candidate is the majority element. Runtime complexity = O(n).
Runtime: O(n) — Bit manipulation: We would need 32 iterations, each calculating the number of 1's for the ith bit of all n numbers. Since a majority must exist, therefore, either count of 1's > count of 0's or vice versa (but can never be equal). The majority number’s ith bit must be the one bit that has the greater count.
*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int x;
        int cnt =0;
        int sz = num.size();
        for(int i = 0; i < sz; i++){
            if(cnt == 0 || num[i] == x){
                x = num[i];
                cnt++;
            }else{
                cnt--;
            }
        }
        return x;
    }
};

class Solution {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(), num.end());
        return num[(num.size() - 1)/2];
    }
};
