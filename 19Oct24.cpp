//    https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/
class Solution {
public:
    char findKthBit(int n, int k) {
        if (k < 1 || (k >= 1 << n)) {
            exit(-1);
        }

        if (n == 1) {
            return '0';
        }

        const int h = 1 << (n - 1);

        if (k == h) {
            return '1';
        }

        if (k < h) {
            return findKthBit(n - 1, k);
        } else {
            auto temp = findKthBit(n - 1, (h << 1) - k);
            return static_cast<int>(!static_cast<bool>(temp - '0')) + '0';
        }
    }
};
