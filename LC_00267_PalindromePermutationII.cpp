/*
Given a string s, return all the palindromic permutations (without duplicates) of it.
Return an empty list if no palindromic permutation could be form.

For example:
Given s = "aabb", return ["abba", "baab"].
Given s = "abc", return [].

Hint:
1. If a palindromic permutation exists, we just need to generate the first half of the string.
2. To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.
*/

//T : O(N!) , S : O(N!)
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> palindromes;
        unordered_map<char, int> counts;
        for (char c : s)
            counts[c]++;
        int odd = 0;
        char mid;
        string half;
        for (auto p : counts) {
            if (p.second & 1) {
                odd++, mid = p.first;
                if (odd > 1)
                    return palindromes;
            }
            half += string(p.second / 2, p.first);
        }
        palindromes = permutations(half);
        for (string& p : palindromes) {
            string t(p);
            reverse(t.begin(), t.end());
            if (odd)
                t = mid + t;
            p += t;
        }
        return palindromes;
    }
private: 
    vector<string> permutations(string& s) {
        vector<string> perms;
        string t(s);
        do {
            perms.push_back(s);
            next_permutation(s.begin(), s.end());
        } while (s != t);
        return perms;
    }
};

//T : O(N!) , S : O(N)
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if (s.empty()) {
            return {};
        }

        unordered_map<char, int> cnt;
        for (const auto& c : s) {
            ++cnt[c];
        }

        string mid, chars;
        for (const auto& kvp : cnt) {
            if (kvp.second % 2) {
                if (mid.empty()) {
                    mid.push_back(kvp.first);
                } else {  // The count of the middle char is at most one. 
                    return {};
                }
            }
            chars.append(kvp.second / 2, kvp.first);
        }
        return permuteUnique(mid, chars);
    }
    
    vector<string> permuteUnique(const string& mid, string& chars) {
        vector<string> result;
        sort(chars.begin(), chars.end());
        do {
            string reverse_chars(chars.crbegin(), chars.crend());
            result.push_back(chars + mid + reverse_chars);
        } while (next_permutation(chars.begin(), chars.end()));
        return result;
    }
};
