//    https://leetcode.com/problems/neighboring-bitwise-xor/description/
class Solution {
public:
    static bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(derived.begin(), derived.end(), 0, bit_xor<>())==0;
    }
};
