//    https://leetcode.com/problems/maximum-number-of-k-divisible-components/
class Solution {
public:
    vector<vector<int>> g;
    int count = 1;

    int dfs(int u, int p, vector<int>& val, int k) {
        int sum = val[u] % k;

        for (int v : g[u]) {
            if (v == p) continue;

            int child = dfs(v, u, val, k);

            if (child == 0) count++;
            else sum = (sum + child) % k;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        g.assign(n, {});
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        count = 1;
        dfs(0, -1, values, k);
        return count;
    }
};
