//      https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/
class Solution {
public:
    bool solve(vector<int>& seq, vector<bool>& used, int i, int n) {
        if (i == seq.size())
            return true;

        if (seq[i] != 0)
            return solve(seq, used, i + 1, n);

        for (int num = n; num >= 1; --num) {
            int nexti = (num == 1) ? i : i + num;

            if (used[num] ||
                (num > 1 && (nexti >= seq.size() || seq[nexti] != 0)))
                continue;

            seq[i] = seq[nexti] = num;
            used[num] = true;

            if (solve(seq, used, i + 1, n))
                return true;

            seq[i] = seq[nexti] = 0;
            used[num] = false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> seq(2 * n - 1, 0);
        vector<bool> visited(n + 1, false);
        solve(seq, visited, 0, n);
        return seq;
    }
};
