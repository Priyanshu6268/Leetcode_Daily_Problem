//    https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = 2 * power[i - 1] % mod;
        }

        int r = n - 1;
        for (int i = 0; i < n; ++i) {
            while (r >= i && nums[i] + nums[r] > target) --r;
            if (r < i) break;

            ans = (ans + power[r - i] % mod) % mod;
        }

        return ans;
    }
  
private:
    static const int mod = 1e9 + 7;
};
