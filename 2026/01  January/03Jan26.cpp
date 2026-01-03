//    https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/
class Solution {
public:
    int numOfWays(int n) {
        int curr[2] = {0, 3}, dp[2][2] = {{3, 2}, {2, 2}}, m = 1000000007;
        while (n) {
            if (n & 1) { const int64_t tmp1 = 1L * curr[0] * dp[0][0] + 1L * curr[1] * dp[1][0], tmp2 = 1L * curr[1] * dp[1][1] + 1L * curr[0] * dp[0][1];
                curr[0] = tmp1 % m, curr[1] = tmp2 % m; }
            int64_t tmp[2][2] = {{0, 0}, {0, 0}};
            for (n /= 2; int i : {0, 1}) for (int j : {0, 1}) for (int k : {0, 1}) tmp[i][k] += 1L * dp[i][j] * dp[j][k];
            for (int i : {0, 1}) for (int j : {0, 1}) dp[i][j] = tmp[i][j] % m;
        }
        return (curr[0] + curr[1]) % m;
    }
};
