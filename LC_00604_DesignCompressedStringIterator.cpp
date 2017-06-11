/*
Design and implement a data structure for a compressed string iterator.
It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases.
Please see here for more details. https://leetcode.com/faq/#different-output

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

Hide Tags Design
*/

class StringIterator {
public:
    StringIterator(string compressedString) : in(compressedString) {}
    
    char next() {
        if (!hasNext())
            return ' ';
        number--;
        return curr;
    }
    
    bool hasNext() {
        while (!number && (in >> curr >> number));
        return number;
    }

private:
    istringstream in;
    char curr;
    int number = 0;
};


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
    }
    
    char next() {
        if (!hasNext())
            return ' ' ;
        count--;
        return c;
    }
    
    bool hasNext() {
        while (count == 0 &&
               idx < data.length() &&
               (('a' <= data[idx] && data[idx] <= 'z') || ('A' <= data[idx] && data[idx] <= 'Z'))) {
                c = data[idx++];
                while (idx < data.length() && '0' <= data[idx] && data[idx] <= '9')
                    count = 10*count + (data[idx++] - '0'); 
        }
        return count > 0;
    }
};

class StringIterator {
private:
    queue<char> chars;
    queue<int> cnts;
public:
    StringIterator(string compressedString) {
        char c;
        int cnt = 0;
        int idx = 0;
        while (idx < compressedString.length()) {
            c = compressedString[idx];
            if ((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) {
                chars.push(c);
                idx++;
                cnt = 0;
                while (idx < compressedString.length() && '0' <= compressedString[idx] && compressedString[idx] <= '9')
                    cnt = 10*cnt + (compressedString[idx++] - '0');
                if (cnt)
                    cnts.push(cnt);
                else
                    chars.pop();
            }
        }
    }
    
    char next() {
        char res = ' ';
        if (!hasNext())
            return res;
        res = chars.front();
        if (--cnts.front() == 0) {
            cnts.pop();
            chars.pop();
        }
        return res; 
    }
    
    bool hasNext() {
        return !cnts.empty();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
