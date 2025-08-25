//    https://leetcode.com/problems/diagonal-traverse/description/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        int i = 0, j = 0;
        bool dir = true; 

        while (ans.size() < m * n) {
            ans.push_back(mat[i][j]);

            if (dir) { 
                if (j == n - 1) { 
                    i++;
                    dir = false;
                } else if (i == 0) { 
                    j++;
                    dir = false;
                } else {
                    i--;
                    j++;
                }
            } else { 
                if (i == m - 1) { 
                    j++;
                    dir = true;
                } else if (j == 0) { 
                    i++;
                    dir = true;
                } else {
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};
