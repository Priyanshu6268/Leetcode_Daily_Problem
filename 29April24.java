//      https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
class Solution {
    public int minOperations(int[] nums, int k) {
        int ans = 0;
        for (int x : nums) {
            ans = ans ^ x;
        }
        ans = ans ^ k;
        int res = 0;
        while (ans > 0) {
            if ((ans & 1) != 0)
                res++;
            ans = ans >> 1;
        }
        return res;
    }
}
