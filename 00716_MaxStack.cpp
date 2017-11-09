/*
Design a stack that supports push, pop, top, and retrieving the maximum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Remove the maximum element in the stack
Hide Tags Stack Data Structure
*/


#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push(int x) {
        const auto idx = idx_to_val_.empty() ? 0 : idx_to_val_.cbegin()->first + 1;
        idx_to_val_[idx] = x;
        val_to_idxs_[x].emplace_back(idx);
    }
    
    int pop() {
        const auto val = idx_to_val_.cbegin()->second;
        remove(val);
        return val;
    }
    
    int top() {
        return idx_to_val_.cbegin()->second;
    }
    
    int peekMax() {
        return val_to_idxs_.cbegin()->first;
    }
    
    int popMax() {
        const auto val = val_to_idxs_.cbegin()->first;
        remove(val);
        return val;
    }

private:    
    void remove(const int val) {
        const auto idx = val_to_idxs_[val].back();
        val_to_idxs_[val].pop_back();
        if (val_to_idxs_[val].empty()) {
            val_to_idxs_.erase(val);
        }
        idx_to_val_.erase(idx);
    }

    map<int, int, greater<int>> idx_to_val_;
    map<int, vector<int>, greater<int>> val_to_idxs_;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */

int main() {
	// your code goes here
	return 0;
}
