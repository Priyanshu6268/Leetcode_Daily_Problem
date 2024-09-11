//    https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_value = start ^ goal;
        int res = 0;
        while (xor_value > 0) {
            res += xor_value & 1; 
            xor_value >>= 1;        
        }
        
        return res;
    }
};
