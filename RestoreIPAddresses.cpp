//============================================================================
// Restore IP Addresses
// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.
//
// For example:
// Given "25525511135",
//
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//============================================================================

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string sol;
        if (s.size() < 4 || s.size() > 12)
            return res;
        restoreIpAddressesHelper(s, 0, 1, sol, res);
        return res;
    }
    
    //start is the index which will be used in the string and k is the kth section in the IP
    void restoreIpAddressesHelper(string &s, int start, int k, string &sol, vector<string> &res) {
        if (start == s.size()) {
            if (k == 5)
            	res.push_back(sol);
            return;
        }
        if(k!=1)//add . if it is not the first section
            sol.push_back('.');
        
        int val = 0; // value in this section
        for(int i=start; i < s.size();i++) {
            val = 10*val+(s[i]-'0');
            if (val > 255)
            	break;
            sol.push_back(s[i]);
            restoreIpAddressesHelper(s, i+1, k+1, sol, res);
            if (val == 0)
            	break;
        }

        while(!sol.empty()){
            if(sol.back()!='.')
                sol.pop_back();//pop all the num in this section
            else
                break;
        }
        if(!sol.empty())//pop the "." if exsits
            sol.pop_back();
    }
};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12)
            return res;
        restoreIpAddressesHelper(s, 0, 4, "", res);
        return res;
    }

    void restoreIpAddressesHelper(string &s, int i, int k, string sol, vector<string> &res) {
        if (i == s.size()) {
            if (k == 0)
            	res.push_back(sol);
            return;
        }
        
        int x = 0;
        int j = i;
        while (j < s.size()) {
            x = 10*x+(s[j]-'0');
            if (x > 255)
            	break;
            if (k != 4 && i == j)
            	sol+=".";
            sol+=s[j++];
            restoreIpAddressesHelper(s, j, k-1, sol, res);
            if (x == 0)
            	break;
        }
    }
};
