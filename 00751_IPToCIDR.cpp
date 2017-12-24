/*
Given a start IP address ip and a number of ips we need to cover n, return a representation of the range as a list (of smallest possible length) of CIDR blocks.

A CIDR block is a string consisting of an IP, followed by a slash, and then the prefix length. For example: "123.45.67.89/20". That prefix length "20" represents the number of common prefix bits in the specified range.

Example 1:
Input: ip = "255.0.0.7", n = 10
Output: ["255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"]
Explanation:
The initial ip address, when converted to binary, looks like this (spaces added for clarity):
255.0.0.7 -> 11111111 00000000 00000000 00000111
The address "255.0.0.7/32" specifies all addresses with a common prefix of 32 bits to the given address,
ie. just this one address.

The address "255.0.0.8/29" specifies all addresses with a common prefix of 29 bits to the given address:
255.0.0.8 -> 11111111 00000000 00000000 00001000
Addresses with common prefix of 29 bits are:
11111111 00000000 00000000 00001000
11111111 00000000 00000000 00001001
11111111 00000000 00000000 00001010
11111111 00000000 00000000 00001011
11111111 00000000 00000000 00001100
11111111 00000000 00000000 00001101
11111111 00000000 00000000 00001110
11111111 00000000 00000000 00001111

The address "255.0.0.16/32" specifies all addresses with a common prefix of 32 bits to the given address,
ie. just 11111111 00000000 00000000 00010000.

In total, the answer specifies the range of 10 ips starting with the address 255.0.0.7 .

There were other representations, such as:
["255.0.0.7/32","255.0.0.8/30", "255.0.0.12/30", "255.0.0.16/32"],
but our answer was the shortest possible.

Also note that a representation beginning with say, "255.0.0.7/30" would be incorrect,
because it includes addresses like 255.0.0.4 = 11111111 00000000 00000000 00000100 
that are outside the specified range.
Note:
ip will be a valid IPv4 address.
Every implied address ip + x (for x < n) will be a valid IPv4 address.
n will be an integer in the range [1, 1000].
*/

class Solution {
private:
    string to_ip(unsigned int x, int step) {
        vector<int> a(4);
        a[3] = x & 255; x >>= 8;
        a[2] = x & 255; x >>= 8;
        a[1] = x & 255; x >>= 8;
        a[0] = x;
        int len = 33;
        while (step) {
            step /= 2;
            --len;
        }
        stringstream ss;
        ss << a[0] << "." << a[1] << "." << a[2] << "." << a[3] << "/" << len;
        return ss.str();
    }

public:
    vector<string> ipToCIDR(string ip, int range) {
        unsigned int x = 0, a[4];
        sscanf(ip.c_str(), "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
        x |= a[0]; x <<= 8;
        x |= a[1]; x <<= 8;
        x |= a[2]; x <<= 8;
        x |= a[3];
        vector<string> ret;
        while (range) {
            unsigned int step = x & -x;
            while (step > range)
                step /= 2;
            ret.push_back(to_ip(x, step));
            x += step;
            range -= step;
        }
        return ret;
    }
};

class Solution {
public:
    vector<string> ipToCIDR(string ip, int range) {
        ip.push_back('.');
        int bits = 0, lastPos = 0;
        for(int i = 0; i < 4; i++) {
            int pos = (int)ip.find('.', lastPos);
            int num = stoi(ip.substr(lastPos, pos - lastPos));
            lastPos = pos + 1;
            bits = (bits << 8) + num;
        }
        vector<string> ans;
        while(range) {
            int suf = 32, cover = 1;
            while(2 * cover <= range && ((bits >> (32 - suf)) & 1) == 0) {
                cover <<= 1;
                suf--;
            }
            range -= cover;
            ans.push_back(to_string((bits >> 24) & 0xff) + "." +
                          to_string((bits >> 16) & 0xff) + "." +
                          to_string((bits >> 8) & 0xff) + "." +
                          to_string((bits) & 0xff) + "/" + to_string(suf));
            bits += 1 << (32 - suf);
        }
        return ans;
    }
};
