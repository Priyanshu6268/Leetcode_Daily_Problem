//    https://leetcode.com/problems/maximum-69-number/description/
class Solution {
public:
    int maximum69Number(int num) {
        int temp = num;
        int index = -1;
        int pos = 0;

        while (temp > 0) {
            if (temp % 10 == 6) index = pos;
            temp /= 10;
            pos++;
        }

        return (index == -1) ? num : num + 3 * static_cast<int>(pow(10, index));
    }
};
