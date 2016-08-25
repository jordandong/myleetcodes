/*
Design an algorithm to encode a list of strings to a string.
The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:
string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}

Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
} 

So Machine 1 does:
string encoded_string = encode(strs);

and Machine 2 does:
vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
1. The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
2. Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
3. Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for (string str : strs)//"len + $" is the sentinel
            s += to_string(str.length()) + '$' + str;
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        size_t n = s.length(), p = 0 ;
        while (p < n) {
            size_t pos = s.find('$', p);
            if (pos == string::npos)
                break;
            size_t sz = stoi(s.substr(p, pos - p));
            strs.push_back(s.substr(pos + 1, sz));
            p = pos + sz + 1;
        }
        return strs;
    }
};

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for (size_t i = 0; i < strs.size(); ++i) {
            size_t len = strs[i].length();
            string tmp;
            for (size_t i = 0, mask = 0xff; i < sizeof(size_t); ++i, len >>= 8) {
                tmp.push_back(len & mask);
            }
            reverse(tmp.begin(), tmp.end());
            s.append(tmp);
            s.append(strs[i]);
        }
    
        return s;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        size_t pos = 0;
    
        while (pos + sizeof(size_t) <= s.length()) {
            size_t len = 0;
            for (size_t i = 0; i < sizeof(size_t); ++i) {
                len <<= 8;
                len += static_cast<unsigned char>(s[pos++]);
            } 
    
            strs.push_back(s.substr(pos, len));
            pos += len;
        }
    
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
