/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int encode; //using low 20 bits to represent 10 letters
        int mask = 0xFFFFF;
        vector<string> res;
        unordered_map<int, bool> mp;
        int i = 0;
        if(s.length() < 10)
            return res;
        
        for(i = 0; i < 10; i++){//first 10 letters are encoded
            encode = (encode<<2) & mask;
            if(s[i] == 'A')
                encode = encode | 0x0;
            else if(s[i] == 'C')
                encode = encode | 0x1;
            else if(s[i] == 'G')
                encode = encode | 0x2;
            else if(s[i] == 'T')
                encode = encode | 0x3;
        }
        mp[encode] = false;//not added into results set

        while(i < s.length()){//each 10 letters are encoded
            encode = (encode<<2) & mask;
            if(s[i] == 'A')
                encode = encode | 0x0;
            else if(s[i] == 'C')
                encode = encode | 0x1;
            else if(s[i] == 'G')
                encode = encode | 0x2;
            else if(s[i] == 'T')
                encode = encode | 0x3;

            if(mp.find(encode) != mp.end()){
                if(mp[encode] == false) // added into results set
                    res.push_back(s.substr(i - 9, 10));
                mp[encode] = true;
            }else{
                mp[encode] = false;
            }
            i++;
        }
        return res;
    }
};
