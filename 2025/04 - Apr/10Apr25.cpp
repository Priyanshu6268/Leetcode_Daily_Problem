//      https://leetcode.com/problems/count-the-number-of-powerful-integers/description/
class Solution {
public:
    typedef long long ll;
    ll solve(int i, int tight, string& num, string& s, int k, int limit, vector<vector<ll>>& dp) {
        if(i == num.size()) return 1;
        if(num.size() == k) return num >= s;
        if(num.size() < k) return 0;

        if(dp[i][tight] != -1) return dp[i][tight];

        ll ans = 0;
        int ub = tight ? min(limit, num[i] - '0') : limit;
        if(i + k >= num.size()) {
            int j = i + k - num.size();
            
            if(s[j] - '0' > ub) return 0;
            
            int dig = s[j] - '0';
            ans += solve(i + 1, tight & (dig == num[i] - '0'), num, s, k, limit, dp);
        } else {
            for(int dig = 0; dig <= ub; dig++) {
                ans += solve(i + 1, tight & (dig == num[i] - '0'), num, s, k, limit, dp);
            }
        }
        return dp[i][tight] = ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        int k = s.size();

        string high = to_string(finish);
        string low = to_string(start - 1);

        vector<vector<ll>> dp1(low.size(), vector<ll>(2, -1));
        ll cnt1 = solve(0, 1, low, s, k, limit, dp1);

        vector<vector<ll>> dp2(high.size(), vector<ll>(2, -1));
        ll cnt2 = solve(0, 1, high, s, k, limit, dp2);
        return cnt2 - cnt1;
    }
};
