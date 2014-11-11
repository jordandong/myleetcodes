/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        data.push(x);
        if(min_stk.empty()){
            min_stk.push(x);
        }else if(x<=min_stk.top()){
            min_stk.push(x);
        }
    }

    void pop() {
        if(!data.empty()){
            if(data.top()==min_stk.top()){
                min_stk.pop();
            }
            data.pop();
        }
    }

    int top() {
        if(!data.empty())
            return data.top();
        else
            return -1;
    }

    int getMin() {
        if(!min_stk.empty())
            return min_stk.top();
        else
            return INT_MAX;
    }
private:
    stack<int> min_stk;
    stack <int> data;
};
