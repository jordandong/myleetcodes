/*
Your task is to design the basic function of Excel and implement the function of sum formula.
Specifically, you need to implement the following functions:

1. Excel(int H, char W): This is the constructor. 
  The inputs represents the height and width of the Excel form. 
  H is a positive integer, range from 1 to 26. It represents the height.
  W is a character range from 'A' to 'Z'. It represents that the width is the number of characters from 'A' to W.
  The Excel form content is represented by a height * width 2D integer array C, it should be initialized to zero.
  You should assume that the first row of C starts from 1, and the first column of C starts from 'A'.

2. void Set(int row, char column, int val): Change the value at C(row, column) to be val.

3. int Get(int row, char column): Return the value at C(row, column).

4. int Sum(int row, char column, List of Strings : numbers):
  This function calculate and set the value at C(row, column), where the value should be the sum of cells represented by numbers.
  This function return the sum result at C(row, column).
  This sum formula should exist until this cell is overlapped by another value or another sum formula.
  numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single cell, then it has the following format : ColRow. For example, "F7" represents the cell at (7, F).
  If the string represent a range of cells, then it has the following format : ColRow1:ColRow2.
  The range will always be a rectangle, and ColRow1 represent the position of the top-left cell, and ColRow2 represents the position of the bottom-right cell.

Example 1:
Excel(3,"C"); 
// construct a 3*3 2D array with all zero.
//   A B C
// 1 0 0 0
// 2 0 0 0
// 3 0 0 0
Set(1, "A", 2);
// set C(1,"A") to be 2.
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 0
Sum(3, "C", ["A1", "A1:B2"]);
// set C(3,"C") to be the sum of value at C(1,"A") and the values sum of the rectangle range whose top-left cell is C(1,"A") and bottom-right cell is C(2,"B"). Return 4. 
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 4
Set(2, "B", 2);
// set C(2,"B") to be 2. Note C(3, "C") should also be changed.
//   A B C
// 1 2 0 0
// 2 0 2 0
// 3 0 0 6

Note:
1. You could assume that there won't be any circular sum reference. For example, A1 = sum(B1) and B1 = sum(A1).
2. The test cases are using double-quotes to represent a character.
3. Please remember to RESET your class variables declared in class Excel, as static/class variables are persisted across multiple test cases. Please see here for more details.
*/

class Excel {
private:
    int **dict;
    int offset, H, W;
    unordered_map<int, vector<string>> mp;
public:
    Excel(int H, char W) {
        offset = 'A';
        this->H = H;
        this->W = W - offset + 1;
        mp.clear();
        dict = new int*[H];
        for (int i = 0; i < H; i++) {
            dict[i] = new int[this->W];
            memset(dict[i], 0, sizeof(int)*this->W);
        }
    }
    
    void set (int r, char c, int v) {
        int k = (r << 10) + c;
        dict[r - 1][c - offset] = v;
        mp.erase(k);
    }
    
    int get (int r, char c) {
        int k = (r << 10) + c;
        if (mp.find(k) == mp.end())
            return dict[r - 1][c - offset];
        return get_cells(mp[k]);
    }
    
    int sum (int r, char c, vector<string> strs) {
        int k = (r << 10) + c;
        dict[r - 1][c - offset] = get_cells(strs);
        mp[k] = strs;
        return dict[r - 1][c - offset];
    }
    
    int get_cells(vector<string> &strs) {
        int res = 0;
        for (auto s : strs) {
            if (s.find(':')  == -1)
                res += get_cell(s);
            else
                res += get_cell_range(s);
        }
        return res;
    }
    
    int get_cell(string &cell) {
        int r = 0, idx = 0;
        char c = cell[idx++];
        while (idx < cell.length())
            r = 10 * r + cell[idx++] - '0';
        return get(r, c);
    }
    
    int get_cell_range(string &cell_range) {
        int rs = 0, re = 0, idx = 0, res = 0;
        char cs, ce;
        
        int seg = cell_range.find(':');
        cs = cell_range[idx++];
        while (idx < seg)
            rs = 10 * rs + cell_range[idx++] - '0';
        
        idx++;
        ce = cell_range[idx++];
        while (idx < cell_range.length())
            re = 10 * re + cell_range[idx++] - '0';
        
        for (int r = rs; r <= re; r++) {
            for (char c = cs; c <= ce; c++) {
                res += get(r, c);
            }
        }
        return res;
    }
};

class Excel {
public:
    Excel(int H, char W) {}
    
    void set(int r, char c, int v) {
        auto i = key(r, c);
        remove_refs(i);
        update_deps(i, v - cells[i].value);
    }
    
    int get(int r, char c) {
        return cells[key(r, c)].value;
    }
    
    int sum (int r, char c, vector<string> strs) {
        auto i = key(r, c);
        remove_refs(i);
        int v = add_refs(i, strs);
        update_deps(i, v - cells[i].value);
        return v;
    }

private:
    struct Cell {
        // dependents and references
        unordered_map<int, int> deps; //{j, count} the value is used by cell j count times
        std::set<int> refs; //{i} the value is part from cell i
        int value;
        Cell() : value(0) {}
    };

    unordered_map<int, Cell> cells;

    int key(int r, char c) {
        return (r - 1) * 26 + (c - 'A');
    }

    // update dependents with dfs following the dependent-chain
    void update_deps(int i, int diff) {
        cells[i].value += diff;
        for (auto &j : cells[i].deps)
            update_deps(j.first, diff * j.second);
    }
    
    void remove_refs(int i) {
        for (auto &j : cells[i].refs)
            cells[j].deps.erase(i);
        cells[i].refs.clear();
    }

    int add_refs(int i, vector<string> &strs) {
        int v = 0;
        for (auto &s : strs) {
            istringstream iss(s);

            int r0, r1;
            char c0, c1;

            if (!(iss >> c0 >> r0 >> c1 >> c1 >> r1))
                r1 = r0, c1 = c0;

            for (int rx = r0; rx <= r1; rx++) {
                for (char cx = c0; cx <= c1; cx++) {
                    int j = key(rx, cx);
                    cells[i].refs.insert(j);
                    cells[j].deps[i]++;
                    v += cells[j].value;
                }
            }
        }
        return v;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
