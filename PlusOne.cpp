//============================================================================
// PlusOne
// Given a number represented as an array of digits, plus one to the number.
//============================================================================

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i = 0; i < digits.size(); i++) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0)
				break;
        }
        if (carry != 0)
			digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main() {
	return 0;
}


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = digits.size();
        if(len < 1)
            return digits;
        
        int carry=(1 + digits[len-1])/10;
        digits[len-1]=(digits[len-1] + 1)%10;
        for(int i= len -2;i>=0;i--){
            int sum = carry + digits[i];
            carry = sum/10;
            digits[i] = sum%10;
        }
        if(carry>0){
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};
