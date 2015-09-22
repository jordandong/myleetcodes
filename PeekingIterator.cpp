/*
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].
Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.

Hint:
1. Think of "looking ahead". You want to cache the next element.
2. Is one variable sufficient? Why or why not?
3. Test your design with call order of peek() before next() vs next() before peek().
4. For a clean implementation, check out Google's guava library source code.

Follow up: How would you extend your design to be generic and work with all types, not just integer?

Hide Tags Design
*/

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    bool last_op_peek;
    int peek_val;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    last_op_peek = false;
	    peek_val = -1;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!last_op_peek) {
            peek_val = Iterator::hasNext() ? Iterator::next() : -1;
            last_op_peek = true;
        }
        return peek_val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int val = peek();
	    last_op_peek = false;
	    return val;
	}

	bool hasNext() const {
	    return last_op_peek ? true : Iterator::hasNext();
	}
};

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
    bool last_op_peek;
    int peek_val;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        last_op_peek = false;
        peek_val = -1;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (last_op_peek)
            return peek_val;
        peek_val = hasNext() ? next() : -1;
        last_op_peek = true;
        return peek_val;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (last_op_peek) {
            last_op_peek = false;
            return peek_val;
        } else {
            return Iterator::next();
        }
    }

    bool hasNext() const {
        return last_op_peek ? true : Iterator::hasNext();
    }
};
