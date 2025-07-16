//    https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(), p = nums[0] & 1;
        int alt = 0, odd = 0;
        for (int num : nums){
            int bit = num & 1;
            if (bit == p){
                alt++;
                p = !p;
            }
            odd += bit;
        }
        return max({alt, odd, n - odd});
    }
};
