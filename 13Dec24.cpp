//      https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/
#include <ranges>
class Solution {
  public:
    long long findScore(vector<int> &nums) {
        long long ans = 0;
        for (int i = 0, n = nums.size(); i < n; i += 2) { 
            int i0 = i;
            while (i + 1 < n && nums[i] > nums[i + 1]) 
                ++i;
            for (int j = i; j >= i0; j -= 2)
                ans += nums[j];
        }
        return ans;
    }
    long long findScore1(vector<int>& nums) {
        vector<int> idx(nums.size());
        iota(idx.begin(), idx.end(), 0);
        ranges::stable_sort(idx, [&](auto a, auto b) { return nums[a] < nums[b]; });
        vector<bool> marked(nums.size());
        long long ans = 0;
        for (int i = 0; i < idx.size(); ++i) {
            if (!marked[idx[i]]) {
                ans += nums[idx[i]];
                if (idx[i] - 1 >= 0) {
                    marked[idx[i] - 1] = true;
                }
                if (idx[i] + 1 < nums.size()) {
                    marked[idx[i] + 1] = true;
                }
            }
        }
        return ans;
    }
};
