//    https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int st=0,end=0;
        int ans = INT_MIN;
        int cntzero = 0;
        while(end < nums.size())
        {
            if(nums[end] == 0) cntzero++;
            while(cntzero > 1)
            {
                if(nums[st] == 0)
                {
                    cntzero--;
                }
                st++;
            }
            ans = max(ans,end-st);
            end++;
        }
        return ans;
    }
};
