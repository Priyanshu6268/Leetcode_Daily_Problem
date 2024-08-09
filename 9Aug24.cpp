//    https://leetcode.com/problems/magic-squares-in-grid/description/
class Solution {
private:
    // Helper function to check if the values are distinct and range from 1 to 9
    bool isValid(const vector<int>& values) {
        vector<bool> seen(10, false);
        for (int value : values) {
            if (value < 1 || value > 9 || seen[value]) {
                return false;
            }
            seen[value] = true;
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                // Get all values in the 3x3 grid
                vector<int> values = {
                    grid[i][j], grid[i][j + 1], grid[i][j + 2],
                    grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2],
                    grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]
                };

                // Check if the values are distinct and range from 1 to 9
                if (!isValid(values)) {
                    continue;  // Skip if they are not distinct or not within 1 to 9
                }

                // Get all rows
                int top = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                int rowMid = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
                int bottom = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

                // Get all columns
                int left = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                int colMid = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
                int right = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

                // Get both diagonals
                int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int d2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

                // Check if all sums are equal (magic square condition)
                if (top == rowMid && rowMid == bottom && bottom == left &&
                    left == colMid && colMid == right && right == d1 && d1 == d2) {
                    count++;
                }
            }
        }

        return count;
    }
};
