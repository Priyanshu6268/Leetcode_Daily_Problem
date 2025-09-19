//    https://leetcode.com/problems/design-spreadsheet/description/
class Spreadsheet {
    vector<array<int, 26>> spreadSheet;
    int getCellValue(const string formula)
    {
        return isalpha(formula.front()) ? spreadSheet[stoi(formula.substr(1)) - 1][formula.front() - 'A'] : stoi(formula);
    }
public:
    Spreadsheet(int rows): spreadSheet(rows) {
        
    }
    
    void setCell(string cell, int value) {
        const int column = cell.front() - 'A';
        const int row = stoi(cell.substr(1)) - 1;
        spreadSheet[row][column] = value;
    }
    
    void resetCell(string cell) {
        const int column = cell.front() - 'A';
        const int row = stoi(cell.substr(1)) - 1;    
        spreadSheet[row][column] = 0;
    }
    
    int getValue(string formula) {
        const int pos = formula.find('+');
        const string x = formula.substr(1, pos - 1);
        const string y = formula.substr(pos + 1);
        const int xvalue = getCellValue(x);
        const int yvalue = getCellValue(y);
        return xvalue + yvalue;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
