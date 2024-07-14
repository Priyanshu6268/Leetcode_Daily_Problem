//    https://leetcode.com/problems/number-of-atoms/description/
class Solution {
public:
    string countOfAtoms(string formula) {
    map<string, int> atomCount;
    stack<map<string, int>> stk;
    int n = formula.size();
    int i = 0;

    while (i < n) {
        if (formula[i] == '(') {
            stk.push(atomCount);
            atomCount.clear();
            i++;
        } else if (formula[i] == ')') {
            map<string, int> temp = atomCount;
            atomCount = stk.top();
            stk.pop();
            i++;
            int count = 0;
            while (i < n && isdigit(formula[i])) {
                count = count * 10 + formula[i] - '0';
                i++;
            }
            count = max(count, 1);
            for (auto& p : temp) {
                atomCount[p.first] += p.second * count;
            }
        } else {
            int start = i;
            i++;
            while (i < n && islower(formula[i])) i++;
            string atom = formula.substr(start, i - start);
            int count = 0;
            while (i < n && isdigit(formula[i])) {
                count = count * 10 + formula[i] - '0';
                i++;
            }
            count = max(count, 1);
            atomCount[atom] += count;
        }
    }

    string result;
    for (auto& p : atomCount) {
        result += p.first;
        if (p.second > 1) result += to_string(p.second);
    }

    return result;

    }
};
