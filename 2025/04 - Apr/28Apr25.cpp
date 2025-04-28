//    https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        int left = 0, right = 0;

        long long sum = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum * (right - left + 1) >= k){
                sum -= nums[left];
                left++;
            }
            
            count += (right - left + 1);
            right++;
        }

        return count;
    }
};
