/*
Given two 1d vectors, implement an iterator to return their elements alternately.
For example, given two 1d vectors:
v1 = [1, 2]
v2 = [3, 4, 5, 6] 
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
*/

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        bs[0] = v1.begin();
        bs[1] = v2.begin();
        es[0] = v1.end();
        es[1] = v2.end();
        p = 0;
    }

    int next() {
        int elem;
        if (bs[0] == es[0])
            elem = *bs[1]++;
        else if (bs[1] == es[1])
            elem = *bs[0]++;
        else {
            elem = *bs[p]++;
            p = (p + 1) % 2;
        }
        return elem;
    }

    bool hasNext() {
        return bs[0] != es[0] || bs[1] != es[1];
    }
private:
    int p;
    vector<int>::iterator bs[2], es[2];
};

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        //if k-d, just added all the k pairs
        if (!v1.empty()) {
            q.push(make_pair(v1.size(), v1.cbegin()));
        }
        if (!v2.empty()) {
            q.push(make_pair(v2.size(), v2.cbegin()));
        }
    }

    int next() {
        const auto len = q.front().first;
        const auto it = q.front().second;
        q.pop();
        if (len > 1) {
            q.push(make_pair(len - 1, it + 1));
        }
        return *it;
    }

    bool hasNext() {
        return !q.empty();
    }

private:
    queue<pair<int, vector<int>::const_iterator>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

