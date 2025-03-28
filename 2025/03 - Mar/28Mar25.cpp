//    https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int, int>> mp;
        int n = grid.size(), m = grid[0].size(), k = queries.size();
        vector<int> ans(k);
        for(int i = 0; i < k; i++) {
            mp.push_back({queries[i], i});
        }
        sort(mp.begin(), mp.end());
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vis[0][0] = 1;
        int dx[4] = {0, 0, -1, +1};
        int dy[4] = {-1, +1, 0, 0};
        int pts = 0;
        for(auto query : mp) {
            while(!pq.empty() && pq.top().first < query.first) {
                int row = pq.top().second.first;
                int col = pq.top().second.second;
                pq.pop();
                pts++;
                for(int i = 0; i < 4; i++) {
                    int nr = row + dx[i];
                    int nc = col + dy[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        pq.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
            ans[query.second] = pts;
        }
        return ans;
    }
};
