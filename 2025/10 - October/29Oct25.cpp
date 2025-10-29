//    https://leetcode.com/problems/smallest-number-with-all-set-bits/
class Solution {
public:
    int smallestNumber(int n) {
        int x = n;
        while ((x & (x + 1)) != 0) {
            x++;
        }
        return x;
    }
};
