//    https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> g(n);
        for (auto &x: edges) {
            inDegree[x[1]] += 1;
            g[x[0]].push_back(x[1]);
        }
        vector<vector<int>> f(n, vector<int>(26, 0));
        vector<bool> vis(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (inDegree[i] == 0) q.push(i);
        int ans = 0;
        while (q.size()) {
            int idx = q.front();
            q.pop();
            vis[idx] = true;
            f[idx][colors[idx] - 'a'] += 1;
            for (int i = 0; i < 26; i++) ans = max(ans, f[idx][i]);
            for (auto &x: g[idx]) {
                for (int i = 0; i < 26; i++)
                    f[x][i] = max(f[x][i], f[idx][i]);
                inDegree[x] -= 1;
                if (inDegree[x] == 0) q.push(x);
            }
        }
        for (int i = 0; i < n; i++) if (!vis[i]) return -1;
        return ans;
    }
};
