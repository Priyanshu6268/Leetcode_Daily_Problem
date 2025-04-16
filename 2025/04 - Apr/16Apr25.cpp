//      https://leetcode.com/problems/count-the-number-of-good-subarrays/description/
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> mp;
        long long n = nums.size();
        long long i = 0, j = 0;
        long long count = 0;
        long long ans = 0;

        while (j < n) {
  
            count += mp[nums[j]];
            mp[nums[j]]++;

            while (count >= k) {
                ans += (n - j); 
                mp[nums[i]]--;
                count -= mp[nums[i]];
                i++;
            }

            j++;
        }

        return ans;
    }
};
