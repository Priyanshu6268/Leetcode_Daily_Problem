//    https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n , vector<int>(m , 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int best = nums1[i] * nums2[j];
                if(i && j) best += max(0 , dp[i - 1][j - 1]);
                if(i) best = max(best , dp[i - 1][j]);
                if(j) best = max(best , dp[i][j - 1]);
                dp[i][j] = best;
            }
        }
        return dp[n - 1][m - 1];
    }
};
