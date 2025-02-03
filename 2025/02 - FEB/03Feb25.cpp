//    https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1,size = 1, i = 1, n = nums.size();
        bool key = false;
        while(i < n){
            while(i < n && nums[i] > nums[i-1]){
                size++;
                ans = max(ans,size);
                i++;
                key = true;
            }
            size = 1;
            while(i < n && nums[i] < nums[i-1]){
                size++;
                ans = max(ans,size);
                i++;
                key = true;
            }
            size = 1;
            if(!key)i++;
            key = false;
        }
        return ans;
    }
};
