//    https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int x : nums) {
            int count = 0;
            while (x) {
                x /= 10;
                count++;
            }
            if (count % 2 == 0) res++;
        }
        return res;
    }
};
