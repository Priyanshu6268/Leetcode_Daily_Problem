//    https://leetcode.com/problems/maximum-difference-between-even-and-odd-freq
class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {};
        for (char c : s) freq[c - 'a']++;
        int max_odd = 0, min_even = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            int f = freq[i];
            if (f == 0) continue;
            if (f & 1) {
                if (f > max_odd) max_odd = f;
            } else {
                if (f < min_even) min_even = f;
            }
        }
        return max_odd - min_even;
    }
};
