/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Hide Tags Stack Data Structure
*/

//one copy of min val in stk with counter
class MinStack {
private:
    stack<pair<int, int> > min_stk;
    stack<int> data;
public:
    void push(int x) {
        data.push(x);
        if(min_stk.empty() || x < min_stk.top().first)
            min_stk.push(make_pair(x, 1));
        else if(x == min_stk.top().first)
            min_stk.top().second++;
    }

    void pop() {
        if(data.size()){
            if(data.top() == min_stk.top().first && --min_stk.top().second == 0)
                min_stk.pop();
            data.pop();
        }
    }

    int top() {
        if(data.size())
            return data.top();
        else
            return -1;
    }

    int getMin() {
        if(min_stk.size())
            return min_stk.top().first;
        else
            return INT_MAX;
    }
};

//keep duplicated min values in stk 
class MinStack {
private:
    stack<int> min_stk;
    stack<int> data;
public:
    void push(int x) {
        data.push(x);
        if(min_stk.empty() || x <= min_stk.top())
            min_stk.push(x);
    }

    void pop() {
        if(data.size()){
            if(data.top() == min_stk.top())
                min_stk.pop();
            data.pop();
        }
    }

    int top() {
        if(data.size())
            return data.top();
        else
            return -1;
    }

    int getMin() {
        if(min_stk.size())
            return min_stk.top();
        else
            return INT_MAX;
    }
};
