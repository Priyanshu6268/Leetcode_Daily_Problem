//    https://leetcode.com/problems/minimum-increment-to-make-array-unique/
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]>=nums[i+1])
            {
                cnt+=(nums[i]+1-nums[i+1]);
                nums[i+1]=++nums[i];
            }            
        }
        return cnt;
    }
};
