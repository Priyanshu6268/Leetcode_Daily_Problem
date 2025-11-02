//    https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        enum CellType { EMPTY, GUARD, WALL, DANGER };
        vector<vector<CellType>> grid(m, vector<CellType>(n, EMPTY));

        for (const auto& guard : guards)
            grid[guard[0]][guard[1]] = GUARD;

        for (const auto& wall : walls)
            grid[wall[0]][wall[1]] = WALL;

        int unguardedCount = m * n - guards.size() - walls.size();
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (const auto& guard : guards) {
            int r = guard[0], c = guard[1];
            for (const auto& dir : directions) {
                int nr = r, nc = c;
                while (true) {
                    nr += dir.first;
                    nc += dir.second;
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == WALL || grid[nr][nc] == GUARD)
                        break;
                    if (grid[nr][nc] == EMPTY) {
                        grid[nr][nc] = DANGER;
                        unguardedCount--;
                    }
                }
            }
        }

        return unguardedCount;
    }
};
