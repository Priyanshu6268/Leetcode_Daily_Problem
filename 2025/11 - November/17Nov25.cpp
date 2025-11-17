//    https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count=0;
        int starti=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1 && starti==-1) starti=i;
            else if(nums[i]==1)
            {
                if(count<k) return false;
                count=0;
            }
            else if(starti!=-1)
            {
                count++;
            }
        }
        return true;
    }
};
