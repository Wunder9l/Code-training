// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> rows;
        rows.resize(numRows);
        RowsIterator iter(numRows);
        for (char c : s) {
            int i = iter.Next();
            // cout << i << endl;
            rows[i].push_back(c);
        }
        string out;
        out.reserve(s.size());
        for (auto& row : rows) {
            for (auto c : row) {
                out.push_back(c);
            }
        }
        return out;
    }
    
private:
    class RowsIterator {
        const int TotalRows;
        int Current = 0;
        bool Down = true;
        
    public:
        RowsIterator(int totalRows) : TotalRows(totalRows) {}
        
        int Next() {
            int returnValue = Current;
            Current += Down ? 1 : -1;
            if (Current == TotalRows) {
                Down = false;
                Current = max(TotalRows - 2, 0);
            }
            if (Current == 0) {
                Down = true;
            }
            return returnValue;
        }        
    };
};