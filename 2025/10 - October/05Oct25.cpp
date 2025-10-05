//    https://leetcode.com/problems/pacific-atlantic-water-flow/description/
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c){
        ocean[r][c] = true;
        for(auto [dr, dc] : directions){
            int nr = r+dr;
            int nc = c+dc;

            if(nr < 0 || nr>= ocean.size() || nc<0 || nc>= ocean[0].size()) continue;
            if(ocean[nr][nc]) continue;
            if(heights[r][c] > heights[nr][nc]) continue;

            dfs(heights, ocean, nr, nc);
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool> (n, false));
        vector<vector<bool>> atlantic(m, vector<bool> (n, false));

        for(int i = 0; i<m; i++) dfs(heights, pacific, i, 0);
        for(int j = 0; j<n; j++) dfs(heights, pacific, 0, j);

        for(int i = 0; i<m; i++) dfs(heights, atlantic, i, n-1);
        for(int j = 0; j<n; j++) dfs(heights, atlantic, m-1, j);

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;

    }
};
