//    https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/
class Solution {
public:
    void createPermu(vector<int>& permu, int m, int current){
        if (m == 0) permu.push_back(current);
        else{
            int lastDigit = current % 10;
            createPermu(permu, m - 1, current * 10 + (lastDigit) % 3 + 1);
            createPermu(permu, m - 1, current * 10 + (lastDigit + 1) % 3 + 1);
        }
    }

    bool check(int a, int b){
        while (a > 0){
            if (a % 10 == b % 10) return false;
            a /= 10;
            b /= 10;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        int mod(1e9 + 7);
        vector<int> permu;
        createPermu(permu, m - 1, 1);
        createPermu(permu, m - 1, 2);
        createPermu(permu, m - 1, 3);

        unordered_map<int, vector<int>> allowedNext;
        for (auto &a: permu) for (auto &b: permu) if (check(a, b)) allowedNext[a].push_back(b);
        unordered_map<int, vector<unsigned int>> dp;
        for (auto &permuToNext: allowedNext){
            dp[permuToNext.first].resize(n, 0);
            dp[permuToNext.first][0] = 1;
        }
        for (int i = 1; i < n; ++i){
            for (auto &permuToNext: allowedNext){
                for (auto &next: permuToNext.second){
                    (dp[next][i] += dp[permuToNext.first][i - 1]) %= mod;
                }
            }
        }
        int ans(0);
        for (auto &pos: dp){
            (ans += pos.second[n - 1]) %= mod;
        }
        return ans;
    }
};
