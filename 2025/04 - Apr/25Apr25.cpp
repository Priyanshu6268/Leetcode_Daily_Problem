//    https://leetcode.com/problems/count-of-interesting-subarrays/description/
class Solution {
public:
    long countInterestingSubarrays(std::vector<int>& nums, int modulo, int k) {
        std::unordered_map<int, long> vals;
        long res = 0;
        int cnt = 0;
        vals[0] = 1;

        for (int v : nums) {
            if (v % modulo == k) {
                cnt++;
            }
            res += vals[(cnt - k + modulo) % modulo];
            vals[cnt % modulo]++;
        }

        return res;
    }
};
