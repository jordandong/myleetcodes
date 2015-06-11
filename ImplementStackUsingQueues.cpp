/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

Notes:
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue -- which means only push to back, pop from front, size, and is empty operations are valid.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and all test cases.

Hide Tags Data Structure
*/

class Stack {
public:
    Stack(){
        idx = 0;
    }
    // Push element x onto stack.
    void push(int x) {
        q[idx ^ 1].push(x);
        while (q[idx].size()) {
            q[idx ^ 1].push(q[idx].front());
            q[idx].pop();
        }
        idx ^= 1;
    }

    // Removes the element on top of the stack.
    void pop(void) {
        if (q[idx].size())
            q[idx].pop();
    }

    // Get the top element.
    int top(void) {
        if (q[idx].size())
            return q[idx].front();
        else 
            return -1;
    }

    // Return whether the stack is empty.
    bool empty(void) {
        return q[idx].empty();    
    }
private:
    int idx;
    queue<int> q[2];
};
