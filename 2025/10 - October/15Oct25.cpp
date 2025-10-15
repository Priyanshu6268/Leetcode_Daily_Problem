//      https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/
class Solution {
public:
    int maxIncreasingSubarrays(const vector<int>& nums) {
        int n = nums.size();
        auto increase = [&](int i) {
            int inc = 1;
            int prev = nums[i - 1];
            while (i < n && prev < nums[i]) {
                prev = nums[i];
                i++;
                inc++;
            }
            return inc;
        };
        int k = 1, previnc = 1;
        for (int i = 1; i < n; i += previnc) {
            int inc = increase(i);
            k = max(k, inc >> 1);
            k = max(k, min(previnc, inc));
            previnc = inc;
        }
        return k;
    }
};
