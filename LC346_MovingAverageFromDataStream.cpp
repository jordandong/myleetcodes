/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : size_(size), sum_(0) {}
    
    double next(int val) {
        if (q_.size() == size_) {
            sum_ -= q_.front();
            q_.pop();
        }
        q_.push(val);
        sum_ += val;
        return 1.0 * sum_ / q_.size();
    }

private:
    int size_;
    int sum_;
    queue<int> q_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
