//    https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/
class Solution {
public:
    int maxOperations(string s) {
        int need = 0, ans = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == '1') need++;
            if (s[i] == '0' && s[i+1] == '1') ans += need;
        }
        if (s[s.size() - 1] == '0') ans += need;
        return ans;
    }
};
