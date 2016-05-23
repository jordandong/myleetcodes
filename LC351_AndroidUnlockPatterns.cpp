/*
Find the total number of patterns of the Android lock screen. The number of key used has to be at least 4, and max 9.

Example:
use 5 keys:
OAB
OOC
OED

OAB
OCD
OOE

Same thing goes with 4, 6, 7, 8, 9 keys. Count the total possible pattern. The order of keys used matters.

Rules:
At-least 4 and at-max 9 dots must be connected.
There can be no jumps
Once a dot is crossed, you can jump over it.

1 2 3         1 2 3        1 2 3        1 2 3
4 5 6         4 5 6        4 5 6        4 5 6
7 8 9         7 8 9        7 8 9        7 8 9
4-1-3-6 x     4-1-9-2 x    2-4-1-3-6 y  6-5-4-1-9-2 y
*/

class AndroidLockPattern {
private:
    bool used[9];
    bool isValid(int index, int last) {		
        if (used[index])
            return false;
        if (last == -1)
            return true;				
        // knight moves and row/col adjcent, 1->0 or 1->2 or 1->4 or 1->6/8 ... 
        if ((index + last)%2 == 1)
            return true;
        int mid = (index +last)/2;
        //diagonals or row/col across 4, 0->8 or 1->7 ...
        if ( mid == 4)
            return used[4];
        // adajcent cells on diagonal, 0->4 or 5->7 ...
        if ((index%3 != last%3) && (index/3 != last/3)) {
            return true;
        }
        //all other adjacent cells, 0->2 or 0->6 ... 
        return used[mid];		
    }

    int calcPatterns(int last,int len) {
        if (len == 0) {
            return 1;				
        } else {
            int sum = 0;
            for (int i = 0; i < 9; i++) {									
                if (isValid(i, last)) {
                    used[i] = true;
                    sum += calcPatterns(i, len - 1);
                    used[i] = false;					
                }
            }
            return sum;
        }			
    }

public:
    int numberOfPatterns() {
        int res =0;
        for (int len = 4; len <= 9; len++) {				
            res += calcPatterns(-1, len);	
            for (int i = 0; i < 9; i++) {
                used[i] = false;					
            }
        }
        return res;
    }
};

int main() {
    AndroidLockPattern alp;
    cout<<alp.numberOfPatterns()<<endl;
    return 0;
}

389112
