/*
TBD
Write a hit counter for hits received in the past 5 minutes.
The HitCounter has two methods:
void hit()   // record a hit.
long getHits()   // Return the number of hits in the last 5 minutes.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// Time:  O(1), amortized
// Space: O(k), k is the count of seconds.
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        count_ = 0;        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        getHits(timestamp); //clear old(more than 300s) hits 
        if (!dq_.empty() && dq_.back().first == timestamp) {
            ++dq_.back().second;
        } else {
            dq_.push_back({timestamp, 1});
        }
        ++count_;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!dq_.empty() && dq_.front().first <= timestamp - k_) {
            count_ -= dq_.front().second;
            dq_.pop_front();
        }
        return count_;
    }

private:
    const int k_ = 300;
    int count_;
    deque<pair<int, int>> dq_;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

int main () {

    HitCounter sol;
    sol.hit(1);
    cout<<sol.getHits(1)<<endl;
    sol.hit(1);
    cout<<sol.getHits(1)<<endl;
    sol.hit(1);
    cout<<sol.getHits(290)<<endl;
    sol.hit(299);
    cout<<sol.getHits(300)<<endl;
    sol.hit(300);
    cout<<sol.getHits(300)<<endl;
    sol.hit(302);
    cout<<sol.getHits(305)<<endl;
}

1
2
3
4
5
3
