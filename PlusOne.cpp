/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Hide Tags Array Math
*/

//T:O(N + N)
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        if(len < 1)
            return digits;
        
        int carry = 1;
        for(int i = len - 1; i >= 0; i--){
            int sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
        }
        if(carry > 0)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};

//T: O(2 * N/2)
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for(auto &e : digits){
            int c = (e + carry)/10;
            e = (e + carry)%10;
            carry = c;
        }
        if(carry)
            digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
