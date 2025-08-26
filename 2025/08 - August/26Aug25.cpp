//    https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& rs) {
        vector<int> mr = *max_element(rs.begin(), rs.end(), [](const vector<int> &r1, const vector<int> &r2) {
            int d1 = r1[0]*r1[0] + r1[1]*r1[1];
            int d2 = r2[0]*r2[0] + r2[1]*r2[1];
            int s1 = r1[0]*r1[1];
            int s2 = r2[0]*r2[1];
            if (d1 != d2) {
                return d1 < d2;
            } else {
                return s1 < s2;
            }
        });

        return mr[0]*mr[1];
    }
};
