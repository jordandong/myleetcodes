/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
For example,
given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/


//T : O(NlogN), S : O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int N = citations.size();
        int i = 0;
        for (i = 0; i < N; i++) {
            if (citations[i] >= N - i)
                break;
        }
        return N - i;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        if (N == 0)
            return 0;
        sort(citations.begin(), citations.end());
        int i = 0;
        while (i < N && citations[i] < N - i)
            i++;
        return N - i;
    }
};
