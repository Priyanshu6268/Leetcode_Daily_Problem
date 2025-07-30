//    https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size() , ans = 1 , MX = 0;
        for(int i=0,cnt=0;i<n;i++){
            if(nums[i] > MX){
                cnt = 0;
                ans = 1;
                MX = nums[i];
            }
            cnt += (nums[i] == MX);
            if(i==n-1 || nums[i]!=nums[i+1]){
                ans = max(ans , cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};
