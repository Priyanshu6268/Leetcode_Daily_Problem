//    https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(energy.begin(), energy.end());

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                dp[i] = max(dp[i], dp[i - k] + dp[i]);
            }
        }

        int ans = dp[n - 1];

        for (int i = n - 1; i > n - 1 - k; i--) {
            if (i < 0) break;

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
