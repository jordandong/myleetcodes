/*
Design and implement a data structure for a compressed string iterator.
It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases.
Please see here for more details.

Example:
StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");
iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
*/

class StringIterator {
private:
    char c;
    int count;
    int idx;
    string data;
public:
    StringIterator(string compressedString) {
        c = ' ';
        idx = 0;
        count = 0;
        data = compressedString;
        c = data[idx];
        if (idx < data.length() && (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) {
            idx++;
            while (idx < data.length() && '0' <= data[idx] && data[idx] <= '9')
                count = 10*count + (data[idx++] - '0');
        }
    }
    
    char next() {
        char res = c;
        count--;
        if (count == 0) {
            c = data[idx];
            if (idx < data.length() && (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) {
                idx++;
                while (idx < data.length() && '0' <= data[idx] && data[idx] <= '9')
                    count = 10*count + (data[idx++] - '0'); 
            }
        }
        
        return count < 0 ? ' ' : res;
    }
    
    bool hasNext() {
        return count > 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
