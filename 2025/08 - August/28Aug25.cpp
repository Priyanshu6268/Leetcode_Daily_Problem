//    https://leetcode.com/problems/sort-matrix-by-diagonals/description/

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n - 1; i++) {
            vector<int> temp;
            int col = m - 1 - i;
            for (int r = 0; r <= i; r++) {
                int val = mat[r][col];
                col++;
                temp.push_back(val);
            }
            sort(temp.begin(), temp.end());
            int idx = 0;
            col = m - 1 - i;
            for (int r = 0; r <= i; r++) {
                mat[r][col] = temp[idx++];
                col++;
            }
        }

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            int col = 0;
            for (int r = i; r < n; r++) {
                int val = mat[r][col];
                col++;
                temp.push_back(val);
            }
            sort(temp.begin(), temp.end(), greater<int>()); 
            int idx = 0;
            col = 0;
            for (int r = i; r < n; r++) {
                mat[r][col] = temp[idx++];
                col++;
            }
        }

        return mat;
    }
};
