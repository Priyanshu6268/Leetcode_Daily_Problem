//   https://leetcode.com/problems/different-ways-to-add-parentheses/description/
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return helper(expression);
    }

private:
    vector<int> helper(const string& expr) {
        vector<int> result;
        for (int i = 0; i < expr.size(); ++i) {
            if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
                auto left = helper(expr.substr(0, i));
                auto right = helper(expr.substr(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (expr[i] == '+') {
                            result.push_back(l + r);
                        } else if (expr[i] == '-') {
                            result.push_back(l - r);
                        } else {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(expr));
        }
        return result;
    }
};
