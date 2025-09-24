//    https://leetcode.com/problems/fraction-to-recurring-decimal/description/
class Solution {
public:
    string fractionToDecimal(long num, long den) {
        unordered_map<long, int> pos;
        string res = ((num < 0 && den > 0) || (num > 0 && den < 0)) ? "-" : "";
        num = abs(num);
        den = abs(den);
        long q = num / den, r = num % den;
        res += to_string(q);
        if (r == 0)
            return res;
        res += ".";
        pos[r] = res.size();
        num = r * 10;
        while (num > 0) {
            q = num / den, r = num % den;
            res += to_string(q);
            if (pos.find(r) != pos.end()) {
                res.insert(pos[r], 1, '(');
                res += ")";
                return res;
            }
            pos[r] = res.size();
            num = r * 10;
        }
        return res;
    }
};
