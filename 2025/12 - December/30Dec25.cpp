//    https://leetcode.com/problems/magic-squares-in-grid/
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;

        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[0].size() - 1; j++) {
                if (grid[i][j] == 5 && isMagic(grid, i, j)) {
                    result++;
                }
            }
        }
        return result;
    }

private:
    bool isMagic(vector<vector<int>>& g, int i, int j) {
        bool seen[10] = {false};

        //check digits 1–9 uniqueness
        for (int r = i - 1; r <= i + 1; r++) {
            for (int c = j - 1; c <= j + 1; c++) {
                int v = g[r][c];
                if (v < 1 || v > 9 || seen[v]) return false;
                seen[v] = true;
            }
        }

        //rows
        return g[i-1][j-1] + g[i-1][j] + g[i-1][j+1] == 15 &&
               g[i][j-1]   + g[i][j]   + g[i][j+1]   == 15 &&
               g[i+1][j-1] + g[i+1][j] + g[i+1][j+1] == 15 &&

               //columns
               g[i-1][j-1] + g[i][j-1] + g[i+1][j-1] == 15 &&
               g[i-1][j]   + g[i][j]   + g[i+1][j]   == 15 &&
               g[i-1][j+1] + g[i][j+1] + g[i+1][j+1] == 15;
    }
};
