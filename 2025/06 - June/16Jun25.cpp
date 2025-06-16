//    https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini=INT_MAX , diff=-1;
        for(int i=0 ; i<nums.size() ; i++){
            mini=min(mini,nums[i]);
            if(nums[i]>mini) diff=max(diff,nums[i]-mini); 
        }
        return diff;    
    }
};
