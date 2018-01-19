/*
Design a max stack that supports push, pop, top, peekMax and popMax.
push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.

Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
 
Note:
1. -1e7 <= x <= 1e7
2. Number of operations won't exceed 10000.
3. The last four operations won't be called when stack is empty.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <list>
using namespace std;

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push(int x) {
        if (s2.empty() || s2.top() <= x)
            s2.push(x);
        s1.push(x);
    }
    
    int pop() {
        if (!s2.empty() && s2.top() == s1.top())
            s2.pop();
        int t = s1.top();
        s1.pop();
        return t;
    }
    
    int top() {
        return s1.top();
    }
    
    int peekMax() {
        return s2.top();
    }
    
    int popMax() {
        int mx = s2.top();
        stack<int> t;
        while (s1.top() != s2.top()) {
            t.push(s1.top());
            s1.pop();
        }
        s1.pop();
        s2.pop();
        while (!t.empty()) {
            push(t.top());
            t.pop();
        }
        return mx;
    }

private:
    stack<int> s1, s2;
};

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push(int x) {
        v.insert(v.begin(), x);
        m[x].push_back(v.begin());
    }
    
    int pop() {
        int x = *v.begin();
        m[x].pop_back();
        if (m[x].empty())
            m.erase(x);
        v.erase(v.begin());
        return x;
    }
    
    int top() {
        return *v.begin();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int x = m.rbegin()->first;
        auto it = m[x].back();
        m[x].pop_back();
        if (m[x].empty())
            m.erase(x);
        v.erase(it);
        return x;
    }

private:
    list<int> v;
    map<int, vector<list<int>::iterator>> m;
};

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
 * MaxStack obj;
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */

int main() {
    // your code goes here
    MaxStack stack;
    stack.push(5); 
    stack.push(1);
    stack.push(5);
    cout<<stack.top()<<endl; //-> 5
    cout<<stack.popMax()<<endl; //-> 5
    cout<<stack.top()<<endl; //-> 1
    cout<<stack.peekMax()<<endl; //-> 5
    cout<<stack.pop()<<endl; //-> 1
    cout<<stack.top()<<endl; //-> 5
    return 0;
}

