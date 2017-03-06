/*
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service.
There is no restriction on how your encode/decode algorithm should work.
You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Note: Do not use class member/global/static variables to store states.
Your encode and decode algorithms should be stateless.
*/

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // Map to store 62 possible characters
        string db = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string shortUrl;
        hash<string> str_hash;
        size_t id = str_hash(longUrl);
        id %= (size_t)pow(62, 6);
        mp[id] = longUrl;
        while (id) {
            shortUrl.push_back(db[id % 62]);
            id /= 62;
        }
        reverse(shortUrl.begin(), shortUrl.end());
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id = 0; // initialize result
        for (int i = 0; i < shortUrl.length(); i++) {
            if ('a' <= shortUrl[i] && shortUrl[i] <= 'z')
                id = id*62 + shortUrl[i] - 'a';
            if ('A' <= shortUrl[i] && shortUrl[i] <= 'Z')
                id = id*62 + shortUrl[i] - 'A' + 26;
            if ('0' <= shortUrl[i] && shortUrl[i] <= '9')
                id = id*62 + shortUrl[i] - '0' + 52;
        }
        return mp[id];
    }
private:
    unordered_map<int, string> mp;
};
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
