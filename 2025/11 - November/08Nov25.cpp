//    https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n==0) return 0;
        int k=31-__builtin_clz(n);
        int numOp=(1<<(k+1))-1;
        return numOp-minimumOneBitOperations(n^(1<<k));
    }
};
