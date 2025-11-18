//    https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
class Solution {
public:
    static bool isOneBitCharacter(const vector<int>& a) {
        const auto it = find(crbegin(a) + 1, crend(a), 0);
        const int len = distance(crbegin(a), it);
        return len & 1;
    }
};
