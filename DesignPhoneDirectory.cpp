/*
Design a Phone Directory which supports the following operations:
1. get: Provide a number which is not assigned to anyone.
2. check: Check if a number is available or not.
3. release: Recycle or release a number.

Example:
// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);
// It can return any available phone number. Here we assume it returns 0.
directory.get();
// Assume it returns 1.
directory.get();
// The number 2 is available, so return true.
directory.check(2);
// It returns 2, the only number that is left.
directory.get();
// The number 2 is no longer available, so return false.
directory.check(2);
// Release number 2 back to the pool.
directory.release(2);
// Number 2 is available again, return true.
directory.check(2);
*/

// init:     Time: O(n), Space: O(n)
// get:      Time: O(1), Space: O(1)
// check:    Time: O(1), Space: O(1)
// release:  Time: O(1), Space: O(1)
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) :
        curr_{0}, numbers_(maxNumbers), used_(maxNumbers) {  // Time: O(n), Space: O(n)
        iota(numbers_.begin(), numbers_.end(), 0);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {  // Time: O(1), Space: O(1)
        if (curr_ == numbers_.size()) {
            return -1;
        }
        const auto number = numbers_[curr_++];
        used_[number] = true;
        return number;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {  // Time: O(1), Space: O(1)
        if (number < 0 || number >= numbers_.size()) {
            return false;
        }
        return !used_[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {  // Time: O(1), Space: O(1)
        if (number < 0 || number >= numbers_.size() || !used_[number]) {
            return;
        }
        used_[number] = false;
        numbers_[--curr_] = number ;
    }

private:
    int curr_;
    vector<int> numbers_;
    vector<bool> used_;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
