/*
Description:

Count the number of prime numbers less than a non-negative number, n

Hint: The number n could be in the order of 100,000 to 5,000,000.

click to show more hints.

References:
How Many Primes Are There?

Sieve of Eratosthenes

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Hide Tags Hash Table Math
*/

class Solution {
public:
    int countPrimes(int n) {
        bool *prime = new bool[n + 1];
        memset(prime, true, n + 1);
        int limit = sqrt(n);
        int cnt = 0;
        for(int i = 2; i <= limit; i++) {
            if(prime[i]){
              for(int j = i * i; j <= n; j += i)
                  prime[j] = false;
            }
        }
        for(int i = 2; i < n; i++)
            if(prime[i])
                cnt++;
        delete prime;
        return cnt;
    }
};

//Memory Limit Exceeded
class Solution {
public:
    int countPrimes(int n) {
        unordered_map<int, bool> prime;
        int limit = sqrt(n);
        for(int i = 2; i < n; i++)
            prime[i] = true;
        
        for(int i = 2; i <= limit; i++) {
            if(prime[i]){
              for(int j = i * i; j <= n; j += i)
                  prime.erase(j);
            }
        }
        return prime.size();
    }
};

