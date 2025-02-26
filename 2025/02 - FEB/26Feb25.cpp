//      https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        long long pre = 0;
        long long maxpos = 0;
        long long maxneg = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (pre < maxneg && pre < 0) {
                maxneg = pre;
            }
            if (pre > maxpos && pre > 0) {
                maxpos = pre;
            }
        }
        return abs(maxpos - maxneg);
    }
};
