//      https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/
class Solution {
public:
    bool check(int idx, string &p, int target)
    {
        if (idx == p.size())
        {
            if (target == 0)
                return true;
            else
                return false;
        }
        if (target < 0)
            return false;
        for (int i = idx; i < p.size(); ++i)
        {
            string x = p.substr(idx, i + 1 - idx);
            int y = stoi(x);
            if (check(i + 1, p, target - y))
                return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        long long ans = 0;
        for (long long i = 1; i <= n; ++i)
        {
            long long x = i * i;
            string p = to_string(x);
            if (check(0, p, i))
                ans += (i * i);
        }
        return ans;
    }
};
