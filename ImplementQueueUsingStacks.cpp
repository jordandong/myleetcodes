/*
Implement the following operations of a queue using stacks.
1. push(x) -- Push element x to the back of queue.
2. pop() -- Removes the element from in front of queue.
3. peek() -- Get the front element.
4. empty() -- Return whether the queue is empty.

Notes:
1. You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
2. Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
3. You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

Hide Tags Stack Data Structure
*/

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;
    // Push element x to the back of queue.
    void push(int x) {
        while(stack2.size()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        if(stack2.size())
            stack2.pop();
    }

    // Get the front element.
    int peek(void) {
        while (stack1.size()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        if (stack2.size()) {
            return stack2.top();
        }else{
            return -1;
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack1.empty() && stack2.empty();
    }
};
