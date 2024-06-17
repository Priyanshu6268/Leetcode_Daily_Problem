//      https://leetcode.com/problems/sum-of-square-numbers/
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            long bSquared = c - a * a;
            long b = sqrt(bSquared);
            if (b * b == bSquared) {
                return true;
            }
        }
        return false;
    }
};
