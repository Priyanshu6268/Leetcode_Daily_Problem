//    https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/
class Solution {
public:
    vector<vector<int>> dp;

    int sol(vector<vector<int>>& f, int i, int j, vector<string>& v, string& t) {
        if (i >= t.length()) 
            return 1;  
        if (j >= f.size()) 
            return 0; 
        if (dp[i][j] != -1) 
            return dp[i][j];
        long long ans = 0;
        ans = sol(f, i, j + 1, v, t) % (long long)(1e9 + 7);
        long long tmp = f[j][t[i] - 'a'];
        if (tmp > 0)
            ans = (ans + (sol(f, i + 1, j + 1, v, t) * tmp) % (long long)(1e9 + 7)) % (long long)(1e9 + 7);
        return dp[i][j] = ans;
    }

    int numWays(vector<string>& v, string t) 
    {
        int n = t.length(), m = v[0].size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        vector<vector<int>> f(m, vector<int>(26));
        for (int j = 0; j < m; j++) 
        {
            for (int i = 0; i < v.size(); i++) 
                ++f[j][v[i][j] - 'a'];
        }
        return sol(f, 0, 0, v, t);
    }
};
