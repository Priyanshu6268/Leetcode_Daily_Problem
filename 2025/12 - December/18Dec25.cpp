//    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description/
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        long long baseProfit = 0;
        vector<long long> orig(n);

        for (int i = 0; i < n; i++) {
            orig[i] = 1LL * strategy[i] * prices[i];
            baseProfit += orig[i];
        }

        vector<long long> prefOrig(n + 1, 0), prefPrice(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefOrig[i + 1] = prefOrig[i] + orig[i];
            prefPrice[i + 1] = prefPrice[i] + prices[i];
        }

        long long maxGain = 0;
        int half = k / 2;

        for (int l = 0; l + k <= n; l++) {
            int r = l + k;

            long long oldSum = prefOrig[r] - prefOrig[l];
            long long sellSum = prefPrice[r] - prefPrice[l + half];
            long long gain = sellSum - oldSum;
            maxGain = max(maxGain, gain);
        }

        return baseProfit + maxGain;
    }
};
