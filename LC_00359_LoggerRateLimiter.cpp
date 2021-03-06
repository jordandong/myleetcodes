/*
Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.
Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.
It is possible that several messages arrive roughly at the same time.

Example:
Logger logger = new Logger();
// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 
// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;
// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;
// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;
// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;
// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;
*/

//T : O(1), S : O(k)
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {}
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false. The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!dq_.empty() && dq_.front().first <= timestamp - 10) {
            printed_.erase(dq_.front().second);
            dq_.pop_front();
        }
        if (printed_.count(message)) {
            return false;
        }
        dq_.push_back({timestamp, message});
        printed_.insert(message);
        return true;
    }

private:
    deque<pair<int, string>> dq_;
    unordered_set<string> printed_;
};

//T : O(1), S : O(N)
class Logger {
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < m[message])
            return false;
        m[message] = timestamp + 10;
        return true;
    }

private:
    unordered_map<string, int> m;
};

int main() {
	  // your code goes here
    Logger logger;
    // logging string "foo" at timestamp 1
    cout<<logger.shouldPrintMessage(1, "foo")<<endl; 
    // logging string "bar" at timestamp 2
    cout<<logger.shouldPrintMessage(2,"bar")<<endl;
    // logging string "foo" at timestamp 3
    cout<<logger.shouldPrintMessage(3,"foo")<<endl;
    // logging string "bar" at timestamp 8
    cout<<logger.shouldPrintMessage(8,"bar")<<endl;
    // logging string "foo" at timestamp 10
    cout<<logger.shouldPrintMessage(10,"foo")<<endl;
    // logging string "foo" at timestamp 11
    cout<<logger.shouldPrintMessage(11,"foo")<<endl;
	return 0;
}

1
1
0
0
0
1
