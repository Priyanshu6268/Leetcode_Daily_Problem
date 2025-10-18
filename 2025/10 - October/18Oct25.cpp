//    https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int last=-1e9;
        for(int i=0;i<nums.size();i++){
            if(last<nums[i]){
                nums[i]=max(last+1,nums[i]-k);
                last=nums[i];
            }else{
                nums[i]=min(last+1,nums[i]+k);
                last=nums[i];
            }
        }
        set<int> ans;
        for(auto it : nums) ans.insert(it);
        return ans.size();
    }
};
